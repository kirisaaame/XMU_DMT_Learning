from fuzzywuzzy import fuzz
from fuzzywuzzy import process
from django.shortcuts import render
import json
from django.core.paginator import Paginator, Page, EmptyPage, PageNotAnInteger
from movierecommendation.models import DoubanMovie
from django.core.exceptions import ObjectDoesNotExist
from django.views.decorators.csrf import csrf_exempt
from django.http import JsonResponse
from movierecommendation.models import QuestionAmswerKB, QuestionIndex
from collections import defaultdict
from django.conf import settings
import os
import re
import jieba
import time
from openai import OpenAI, APIError
import logging

logger = logging.getLogger(__name__)

# 电影推荐首页
def doubanRecommendation(request):
    movie_list = DoubanMovie.objects.all()
    paginator = Paginator(movie_list, 20)
    page = request.GET.get('page')
    if page:
        data_list = paginator.page(page).object_list
    else:
        data_list = paginator.page(1).object_list

    try:
        page_obj = paginator.page(page)
    except PageNotAnInteger:
        page_obj = paginator.page(1)
    except EmptyPage:
        page_obj = paginator.page(paginator.num_pages)

    return render(request, 'doubanRecommendation.html', {
        'page_object': page_obj,
        'data_list': data_list
    })

# 问答页面
@csrf_exempt
def questionAnswering(request):
    return render(request, 'questionAnswering.html')

# 精确匹配 + 索引检索
@csrf_exempt
def searchanswer(request):
    logger.info(f"SearchAnswer 请求参数: {request.GET.dict()}")
    res = {
        'status': 404,
        'text': 'Unknown request!',
        'answer_exact': '检索不到答案',
        'answer_app': '检索不到答案'
    }
    if request.method == 'GET':
        btn_id = request.GET.get('id')
        question = request.GET.get('text', '').strip()
        if btn_id != 'chatbotsendbtn':
            res.update({'status': 400, 'text': '无效的按钮 ID'})
            return JsonResponse(res, json_dumps_params={'ensure_ascii': False})
        if not question:
            res.update({'status': 400, 'text': '问题不能为空！'})
            return JsonResponse(res, json_dumps_params={'ensure_ascii': False})

        res.update({'status': 201, 'text': question})
        # 精确匹配
        try:
            qa = QuestionAmswerKB.objects.get(question=question)
            res.update({'status': 200, 'answer_exact': qa.answer})
        except QuestionAmswerKB.DoesNotExist:
            pass
        # 倒排索引检索
        start = time.time()
        terms = [t for t in jieba.lcut(question) if t.strip()]
        scores = defaultdict(float)
        for term in terms:
            try:
                idx = QuestionIndex.objects.get(keyword=term)
                ids = json.loads(idx.doclist)
                for doc_id in ids:
                    doc = QuestionAmswerKB.objects.get(id=doc_id)
                    doc_terms = jieba.lcut(doc.question)
                    if doc_terms:
                        scores[doc_id] += doc_terms.count(term) / len(doc_terms)
            except QuestionIndex.DoesNotExist:
                continue
        if scores:
            best = max(scores, key=scores.get)
            qa2 = QuestionAmswerKB.objects.get(id=best)
            res.update({
                'status': 200,
                'answer_app': qa2.answer,
                'time_index': round(time.time() - start, 4)
            })
    return JsonResponse(res, json_dumps_params={'ensure_ascii': False})

# 建立/刷新索引
@csrf_exempt
def buildindex(request):
    res = {'status': 404, 'text': 'Unknown request!'}
    if request.method == 'POST':
        btn = request.POST.get('id')
        if btn == 'submit2index':
            # 加载停用词
            stopfile = os.path.join(settings.STATIC_ROOT, 'refs', 'stopwords.txt')
            stopwords = []
            with open(stopfile, encoding='utf-8') as f:
                stopwords = [w.strip() for w in f if w.strip()]
            # 收集问题分词
            all_q = QuestionAmswerKB.objects.values('id', 'question')
            term_map = {}
            all_terms = set()
            for item in all_q:
                qid, txt = item['id'], item['question']
                clean = re.sub(r'[^\w一-龥]+', '', txt)
                terms = [w for w in jieba.lcut(clean) if w not in stopwords and w.strip()]
                term_map[qid] = terms
                all_terms.update(terms)
            # 写入或更新索引
            for term in all_terms:
                docs = [qid for qid, ts in term_map.items() if term in ts]
                js = json.dumps(docs, ensure_ascii=False)
                try:
                    idx = QuestionIndex.objects.get(keyword=term)
                    idx.doclist = js
                    idx.save()
                except QuestionIndex.DoesNotExist:
                    QuestionIndex.objects.create(keyword=term, doclist=js)
            res.update({'status': 200, 'text': 'Index successfully!'})
    return JsonResponse(res, json_dumps_params={'ensure_ascii': False})

# DeepSeek API 调用
@csrf_exempt
def deepseekanswer(request):
    logger.info(f"DeepSeek 请求参数: {request.GET.dict()}")
    question = request.GET.get('text', '').strip()
    if not question:
        return JsonResponse({'status': 400, 'text': '问题不能为空！', 'answer_api': '检索不到答案'}, json_dumps_params={'ensure_ascii': False})
    client = OpenAI(api_key="sk-xxx", base_url="https://api.deepseek.com")
    res = {'status': 500, 'text': '未知错误', 'answer_api': '检索不到答案'}
    try:
        resp = client.chat.completions.create(
            model="deepseek-chat",
            messages=[{'role': 'system', 'content': 'You are a helpful assistant'}, {'role': 'user', 'content': question}],
            stream=False,
            timeout=15
        )
        ans = resp.choices[0].message.content
        res.update({'status': 200, 'text': 'API 调用成功', 'answer_api': ans})
    except APIError as e:
        res.update({'status': getattr(e, 'status_code', 500), 'text': f"API 错误: {e}", 'answer_api': '检索不到答案'})
    except Exception as e:
        res.update({'status': 500, 'text': f"其他错误: {e}", 'answer_api': '检索不到答案'})
    return JsonResponse(res, json_dumps_params={'ensure_ascii': False})
