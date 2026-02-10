from fuzzywuzzy import fuzz
from fuzzywuzzy import process
from django.shortcuts import render
import json
from django.core.paginator import Paginator, Page, EmptyPage, PageNotAnInteger
from movierecommendation.models import DoubanMovie
from django.core.exceptions import ObjectDoesNotExist
from django.views.decorators.csrf import csrf_exempt
from django.http import HttpResponse
from movierecommendation.models import QuestionAmswerKB


# Create your views here.
def doubanRecommendation(request):
    movie_list = DoubanMovie.objects.all()
    paginator = Paginator(movie_list, 20)
    page = request.GET.get('page')
    data_list = []
    if page:
        data_list = paginator.page(page).object_list
    else:
        data_list = paginator.page(1).object_list
    try:
        page_object = paginator.page(page)
    except PageNotAnInteger:
        page_object = paginator.page(1)
    except EmptyPage:
        page_object = paginator.page(paginator.num_pages)
    return render(request, "doubanRecommendation.html", {
        'page_object': page_object,
        'data_list': data_list
    })

def questionAnswering(request):
    return render(request, "questionAnswering.html")

@csrf_exempt
def searchanswer(request):
    res = {
        'status': 404,
        'text': 'Unknown request!'
    }
    if request.method == 'GET':
        name = request.GET['id']
        if name == 'chatbotsendbtn':
            try:
                # 获取前端的问题文本
                text = request.GET['text']
                
                # 获取所有问题，使用 fuzzywuzzy 库来计算相似度
                all_questions = QuestionAmswerKB.objects.all()
                best_match = None
                highest_similarity = 0
                for qa in all_questions:
                    similarity = fuzz.partial_ratio(text, qa.question)
                    # 如果相似度大于某个阈值（例如 70%），认为是有效的匹配
                    if similarity > highest_similarity:
                        highest_similarity = similarity
                        best_match = qa
                
                # 判断是否有匹配
                if best_match and highest_similarity >= 70:
                    res = {
                        'status': 200,
                        'answer': best_match.answer,
                        'match_type': 'fuzzy',
                        'similarity': highest_similarity
                    }
                else:
                    res = {
                        'status': 201,
                        'answer': 'No fuzzy match found!',
                        'match_type': 'fuzzy'
                    }

            except Exception as e:
                res = {
                    'status': 500,
                    'answer': str(e)
                }
    return HttpResponse(json.dumps(res), content_type='application/json')
