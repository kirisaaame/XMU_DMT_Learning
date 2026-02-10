from django.shortcuts import render
from movierecommendation.models import QuestionAnswerKB,QuestionIndex
from django.http import HttpResponse
import json
from django.views.decorators.csrf import csrf_exempt
from django.core.exceptions import ObjectDoesNotExist
from django.conf import settings
import os
import re
import jieba
from collections import defaultdict
import jieba.posseg as psg
from wordcloud import WordCloud
import matplotlib.pyplot as plt
from io import BytesIO
import base64






# 定义问答页面.
def questionAnswering(request):
    return render(request, 'questionAnswering.html')

# 定义问答检索请求链接.
@csrf_exempt
def searchanswer(request):
    res = {
        'status': 404,
        'text': 'Unknown request!',
        'answer_exact': '检索不到答案',
        'answer_app': '检索不到答案'
    }
    if request.method == 'GET':
        name = request.GET['id']
        if name == 'chatbotsendbtn':
            try:
                # 获取前端的问题文本
                text = request.GET['text']
                if not text:
                    res['status'] = 400
                    res['text'] = '问题不能为空！'
                    return HttpResponse(json.dumps(res), content_type='application/json')

                res['status'] = 201
                res['text'] = text

                # 获取操作类型
                opType = request.GET['opType']
                match opType:
                    case "search":
                        try:
                            # 检索问题，匹配答案
                            # 精确检索太苛刻了，如何实现近似问题检索？
                            qa_rec_exact = QuestionAnswerKB.objects.get(question=text)
                            if qa_rec_exact:
                                res['status'] = 200
                                res['answer_exact'] = qa_rec_exact.answer
                        except QuestionAnswerKB.DoesNotExist:
                            res['status'] = 201

                        # 基于索引的检索结果
                        # 这里实现了基于词频作为文档权重的排序
                        # 如何实现其他排序算法呢？
                        terms = jieba.lcut(text) # 分词
                        terms = [term for term in terms if term.strip()]  # 过滤空字符

                        # 统计关键词匹配次数
                        doc_scores = defaultdict(int)  # 记录每个文档的匹配得分
                        for term in terms:
                            try:
                                # 查询倒排索引
                                index_entry = QuestionIndex.objects.get(keyword=term)
                                doc_ids = json.loads(index_entry.doclist)  # 获取包含该关键词的文档ID列表
                                for doc_id in doc_ids:
                                    doc_scores[doc_id] += 1
                            except QuestionIndex.DoesNotExist:
                                continue  # 关键词不存在于索引中，跳过

                        # 根据匹配得分排序
                        if doc_scores:
                            # 按得分从高到低排序
                            sorted_docs = sorted(doc_scores.items(), key=lambda x: x[1], reverse=True)
                            # 获取得分最高的文档ID
                            best_doc_id = sorted_docs[0][0]
                            # 查询对应的问答记录
                            qa_rec_app = QuestionAnswerKB.objects.get(id=best_doc_id)
                            if qa_rec_app:
                                res['status'] = 200
                                res['answer_app'] = qa_rec_app.answer

                    case "pos":
                        # 词性标注代码如下
                        # 注意这里只标注了名词和动词
                        seg_list = psg.cut(text)
                        new_text = ''
                        for word, pos in seg_list:
                            new_word = word
                            if pos == 'n': # 名词
                                new_word = '<span style="background-color: yellow;">' + word + '</span>' # yellow background
                            elif pos == 'v': # 动词
                                new_word = '<span style="background-color: green;">' + word + '</span>' # green background
                            elif pos == 'a':  # 形容词
                                new_word = '<span style="background-color: blue;">' + word + '</span>'  # blue background
                            elif pos == 'd':  # 副词
                                new_word = '<span style="background-color: pink;">' + word + '</span>'  # pink background
                            elif pos == 'r':  # 代词
                                new_word = '<span style="background-color: orange;">' + word + '</span>'  # orange background
                            new_text += new_word
                            res['status'] = 200
                            res['answer_exact'] = new_text
                    case "entity":
                        # 实体识别逻辑
                        seg_list = psg.cut(text)
                        entity_text = ''
                        for word, pos in seg_list:
                            if pos in ['nr', 'ns', 'nt']:  # 人名、地名、机构名
                                entity_text += '<span style="background-color: lightblue;">' + word + '</span> '
                            else:
                                entity_text += word + ' '
                        res['status'] = 200
                        res['answer_exact'] = entity_text
                    case "wcloud":
                        # 词云分析逻辑
                        from jieba import analyse
                        kw1 = jieba.analyse.textrank(text, topK=50, withWeight=True, allowPOS=('ns', 'n'))
                        words_frequence = {x[0]: x[1] for x in kw1}

                        # 加载词云图背景图片
                        static_filepath = os.path.join(settings.STATIC_ROOT, 'refs')
                        file_bg_path = os.path.join(static_filepath, 'cat.jpg')
                        backgroud_Image = plt.imread(file_bg_path)

                        # 加载字体文件
                        file_font_path = os.path.join(static_filepath, 'simsun.ttc')
                        wordcloud = WordCloud(font_path=file_font_path, mask=backgroud_Image, repeat=True, background_color='white')
                        wordcloud = wordcloud.fit_words(words_frequence)

                        # 生成词云图
                        plt.imshow(wordcloud)
                        plt.axis("off")
                        sio = BytesIO()
                        plt.savefig(sio, format='png', bbox_inches='tight', pad_inches=0.0)
                        cloud_data = base64.encodebytes(sio.getvalue()).decode()
                        cloud_src = 'data:image/png;base64,' + str(cloud_data)
                        plt.close()

                        # 保存图片到文件
                        file_img_path = os.path.join(static_filepath, 'wordcloudcluster.jpg')
                        wordcloud.to_file(file_img_path)

                        # 返回词云图路径
                        res['status'] = 200
                        static_url = os.path.join(settings.STATIC_URL, 'refs')
                        res['answer_exact'] = os.path.join(static_url, 'wordcloudcluster.jpg')



            except ObjectDoesNotExist:
                res['status'] = 201

    return HttpResponse(json.dumps(res), content_type='application/json')

# 定义索引请求链接.
@csrf_exempt
def buildindex(request):
    res = {
        'status': 404,
        'text': 'Unknown request!'
    }
    if request.method == 'POST':
        name = request.POST['id']
        if name == 'submit2index':
            # 初始化停用词列表
            # 注意：从网上下载一个较为全面完整的stopwords.txt用于本次任务。此处只是一个简单的示例文件
            stopwords = []
            static_filepath = os.path.join(settings.STATIC_ROOT, 'refs')
            file_path = os.path.join(static_filepath, 'stopwords.txt')
            for word in open(file_path, encoding='utf-8'):
                stopwords.append(word.strip())
            # 获取所有问题的文本属性用于索引
            question_list = QuestionAnswerKB.objects.values('id', 'question')
            all_keywords = []
            question_set = dict()
            for question in question_list:
                question_id = question['id']
                text = question['question']
                # 正则表达式去除非文字和数字的字符
                question_text = re.sub(r'[^\w]+', '', text.strip())
                cut_text=jieba.cut(question_text, cut_all=False)
                keywordlist = []
                for word in cut_text:
                    # 此处去停用词
                    if word not in stopwords:
                        keywordlist.append(word)
                all_keywords.extend(keywordlist)
                question_set[question_id] = keywordlist
            # 利用set删除重复keywords
            set_all_keywords = set(all_keywords)
            # 建立倒排索引
            for term in set_all_keywords:
                temp=[]
                for m_id in question_set.keys():
                    cut_text = question_set[m_id]
                    if term in cut_text:
                        temp.append(m_id)
                # 存储索引到数据库
                try:
                    exist_list = QuestionIndex.objects.get(keyword=term)
                    exist_list.question_doclist = json.dumps(temp)
                    exist_list.save()
                except ObjectDoesNotExist:
                    new_list = QuestionIndex(keyword=term, doclist=json.dumps(temp))
                    new_list.save()
            res = {
                'status': 200,
                'text': 'Index successfully!'
            }

    return HttpResponse(json.dumps(res), content_type='application/json')

