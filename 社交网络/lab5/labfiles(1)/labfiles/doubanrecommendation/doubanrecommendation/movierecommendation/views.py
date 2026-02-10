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
import jieba.posseg as psg
from jieba import analyse
from collections import defaultdict

from wordcloud import WordCloud
import matplotlib.pyplot as plt
from io import BytesIO
import base64

import uuid

import pandas as pd
from sklearn.model_selection import cross_val_score,train_test_split
from sklearn.preprocessing import LabelEncoder
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.neighbors import KNeighborsClassifier
import matplotlib as mpl
import matplotlib.pyplot as plt

from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.cluster import DBSCAN
from openai import OpenAI, APIError

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
        name = request.GET.get('id', '')
        if name != 'chatbotsendbtn':
            return HttpResponse(json.dumps(res), content_type='application/json')

        text = request.GET.get('text', '').strip()
        if not text:
            res.update({'status': 400, 'text': '问题不能为空！'})
            return HttpResponse(json.dumps(res), content_type='application/json')

        opType = request.GET.get('opType', 'search')
        res['status'] = 201
        res['text'] = text

    try:
        match opType:
            case 'search':
                # 精确检索
                try:
                    qa = QuestionAnswerKB.objects.get(question=text)
                    res.update({'status': 200, 'answer_exact': qa.answer})
                except QuestionAnswerKB.DoesNotExist:
                    pass

                # 基于索引检索
                terms = [t for t in jieba.lcut(text) if t.strip()]
                scores = defaultdict(int)
                for term in terms:
                    try:
                        idx = QuestionIndex.objects.get(keyword=term)
                        for did in json.loads(idx.doclist):
                            scores[did] += 1
                    except QuestionIndex.DoesNotExist:
                        continue
                if scores:
                    best_id = max(scores, key=scores.get)
                    qa2 = QuestionAnswerKB.objects.get(id=best_id)
                    res.update({'status': 200, 'answer_app': qa2.answer})

            case 'pos':
                segs = psg.cut(text)
                annotated = ''.join(
                    f'<span style="background:{"yellow" if p=="n" else "green"}">{w}</span>'
                    if p in ('n','v') else w
                    for w, p in segs
                )
                res.update({'status': 200, 'answer_exact': annotated})

            case 'entity':
                segs = psg.cut(text)
                annotated = ''.join(
                    f'<span style="background:{"orange" if p=="nr" else "purple"}">{w}</span>'
                    if p in ('nr','ns') else w
                    for w, p in segs
                )
                res.update({'status': 200, 'answer_exact': annotated})

            case 'wcloud':
                # 1. 提取关键词
                kw = analyse.textrank(
                    text, topK=50, withWeight=True, allowPOS=('ns','n')
                )
                freqs = {w: wt for w, wt in kw}

                # 2. 加载猫咪遮罩图
                mask_path = os.path.join(settings.STATIC_ROOT, 'refs', 'cat.jpg')
                try:
                    import matplotlib.pyplot as plt
                    mask_img = plt.imread(mask_path)
                except:
                    mask_img = None

                # 3. 生成词云
                wc = WordCloud(
                    font_path=os.path.join(settings.STATIC_ROOT, 'refs', 'simsun.ttc'),
                    mask=mask_img,
                    background_color='white',
                    width=600,
                    height=400
                ).fit_words(freqs)

                # 4. 转为 Base64 并返回
                buf = BytesIO()
                wc.to_image().save(buf, format='PNG')
                b64 = base64.b64encode(buf.getvalue()).decode('utf-8')
                data_uri = f"data:image/png;base64,{b64}"

                res.update({
                    'status': 200,
                    'text': '已生成以 cat.jpg 为底的词云图：',
                    'answer_exact': data_uri
                })

            case "classification":
                        # 获取数据集文件名
                        fileName = text
                        static_filepath = os.path.join(settings.STATIC_ROOT, 'upload')
                        trainDF = pd.read_excel(static_filepath + "/" + fileName)

                        # 检查列名是否存在
                        # required_columns = ['text', 'label']
                        feature_column = trainDF.columns[0]
                        label_column = trainDF.columns[1]
                        
                            # if col not in trainDF.columns:
                            #     print(f"列名 {col} 不存在于 DataFrame 中。")
                            #     print(f"DataFrame 的列名有: {trainDF.columns}")
                            #     break
                        # 将特征列的数据类型转换为字符串
                        trainDF[feature_column] = trainDF[feature_column].astype(str)
                        trainDF[label_column] = trainDF[label_column].astype(str)

                        train_x, test_x, train_y, test_y = train_test_split(trainDF[feature_column], trainDF[label_column], test_size=0.2)


                        # 确保 train_x 和 test_x 为字符串类型
                        train_x = train_x.astype(str)
                        test_x = test_x.astype(str)

                        # 将数据集划分为训练集和测试集
                        # train_x, test_x, train_y, test_y = train_test_split(trainDF['text'], trainDF['label'], test_size=0.2)

                        #label编码为目标变量
                        encoder = LabelEncoder()
                        train_y = encoder.fit_transform(train_y)
                        test_y = encoder.fit_transform(test_y)

                        # 初始化停用词列表
                        # 注意：从网上下载一个较为全面完整的stopwords.txt用于本次任务。此处只是一个简单的示例文件
                        stopwords = []
                        static_filepath = os.path.join(settings.STATIC_ROOT, 'refs')
                        file_path = os.path.join(static_filepath, 'stopwords.txt')
                        for word in open(file_path, encoding='utf-8'):
                            stopwords.append(word.strip())
                       
                        #定义分词函数 
                        def tokenizer(s):
                            words=[]
                            cut = jieba.cut(s)
                            for word in cut:
                                words.append(word)
                            return words

                        
                        
                        #创建一个向量计数器对象
                        count = CountVectorizer(tokenizer=tokenizer, stop_words=list(stopwords))
                        count.fit(trainDF[feature_column])

                        #使用向量计数器对象转换训练集和测试集
                        xtrain_count = count.transform(train_x)
                        xtest_count = count.transform(test_x)

                        kNN_classifier = KNeighborsClassifier(n_neighbors=2) #初始化k近邻算法对象
                        kNN_classifier.fit(xtrain_count, train_y) #对训练集进行训练
                        label_predict = kNN_classifier.predict(xtest_count) #对测试集进行预测

                        # 可视化
                        # 默认情况下，matplotlib不支持中文显示，设置一下
                        mpl.rcParams['font.family'] = 'SimHei'
                        # 设置在中文字体时，能够正常显示负号-
                        mpl.rcParams['axes.unicode_minus'] = False
                        # 由于文本特征转换后是高维的，这里只取前两维进行可视化
                        xtrain_array = xtrain_count.toarray()
                        if xtrain_array.shape[1] >= 2:
                            # 可视化训练集的数据
                            plt.scatter(x=xtrain_array[:, 0], y=xtrain_array[:, 1], c=train_y)

                            # 可视化测试集的数据
                            xtest_array = xtest_count.toarray()
                            right = xtest_array[label_predict == test_y]
                            wrong = xtest_array[label_predict != test_y]
                            if right.shape[0] > 0:
                                plt.scatter(x=right[:, 0], y=right[:, 1], color='c', marker='x', label='right')
                            if wrong.shape[0] > 0:
                                plt.scatter(x=wrong[:, 0], y=wrong[:, 1], color='m', marker='>', label='wrong')

                            plt.xlabel("文本特征1")
                            plt.ylabel("文本特征2")
                            plt.title("KNN分类结果显示")
                            plt.legend(loc='best')

                            sio = BytesIO()
                            plt.savefig(sio, format='png', bbox_inches='tight', pad_inches=0.0)
                            data = base64.encodebytes(sio.getvalue()).decode()
                            src = 'data:image/png;base64,' + str(data)
                            plt.close()

                            # 计算准确率
                            accuracy = sum(label_predict == test_y) / len(test_y)
                        res = {
                            'status': 200,
                            'text': "分类准确率为： " + str(accuracy),
                            'image': src
                        }

            case 'clustering':
                # 1. 读入上传的 Excel（text 变量是文件名）
                upload_dir = os.path.join(settings.STATIC_ROOT, 'upload')
                df = pd.read_excel(os.path.join(upload_dir, text))
                # 假设第一列是要做聚类的文本
                docs = df.iloc[:,0].astype(str).apply(lambda s: " ".join(jieba.lcut(s)))

                # 2. TF-IDF 向量化
                vec = TfidfVectorizer(min_df=3, max_df=0.9, ngram_range=(1,2))
                X = vec.fit_transform(docs)

                # 3. DBSCAN 聚类
                model = DBSCAN(eps=0.6, min_samples=5, metric='cosine')
                labels = model.fit_predict(X)
                df['cluster'] = labels

                # 4. 对簇 0 生成词频
                texts0 = df[df['cluster']==0].iloc[:,0].astype(str)
                freqs = {}
                if not texts0.empty:
                    for w, wt in analyse.textrank(" ".join(texts0),
                                                  topK=50, withWeight=True):
                        freqs[w] = wt

                # 5. 加载猫咪遮罩图
                mask_path = os.path.join(settings.STATIC_ROOT, 'refs', 'cat.jpg')
                try:
                    import matplotlib.pyplot as plt
                    mask_img = plt.imread(mask_path)
                except:
                    mask_img = None

                # 6. 生成词云
                wc = WordCloud(
                    font_path=os.path.join(settings.STATIC_ROOT,'refs','simsun.ttc'),
                    mask=mask_img,
                    background_color='white',
                    width=600, height=400
                ).fit_words(freqs)

                # 7. 渲染到内存并转 Base64
                buf = BytesIO()
                wc.to_image().save(buf, format='PNG')
                b64 = base64.b64encode(buf.getvalue()).decode('utf-8')
                data_uri = f"data:image/png;base64,{b64}"

                # 8. 返回给前端
                res = {
                    'status': 200,
                    'text': f"DBSCAN 聚类完成，共 {len(set(labels)) - (1 if -1 in labels else 0)} 个簇，噪声 {list(labels).count(-1)} 条。",
                    'image': data_uri
                }


    except ObjectDoesNotExist:
        res['status'] = 201

    return HttpResponse(json.dumps(res), content_type='application/json')

# 定义 deepseekanswer 请求链接.
@csrf_exempt
def deepseekanswer(request):
    res = {
        'status': 404,
        'text': 'Unknown request!',
        'answer_api': '检索不到答案'
    }
    client = OpenAI(api_key="sk-b8516c0a268e4855ac85c1daba1473ef", base_url="https://api.deepseek.com")
    try:
        response = client.chat.completions.create(
            model="deepseek-chat",
            messages=[
                {"role": "system", "content": "You are a helpful assistant"},  # 设定 AI 的角色（可选）
                {"role": "user", "content": request.GET['text']},  # 用户的问题
            ],
            stream=False
        )

        res['status'] = 200  # 成功状态码
        res['text'] = "API 调用成功"
        res['answer_api'] = response.choices[0].message.content
    except APIError as e:
        res['status'] = e.status_code if hasattr(e, 'status_code') else 500
        res['text'] = f"API 错误: {str(e)}"
        res['answer_api'] = '检索不到答案'

    except Exception as e:
        # 其他未知错误
        res['status'] = 500
        res['text'] = f"其他错误: {str(e)}"
        res['answer_api'] = '检索不到答案'

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

# 定义文件上传请求链接.
@csrf_exempt
def uploaddatafile(request):
    res = {
        'status': 404,
        'text': 'Unknown request!'
    }
    if request.method == 'POST':
        # 根name取 file 的值
        file = request.FILES.get('excelfile')
        # 创建upload文件夹
        static_filepath = os.path.join(settings.STATIC_ROOT, 'upload')
        if not os.path.exists(static_filepath):
            os.makedirs(static_filepath)
        try:
            # 循环二进制写入
            ext = file.name.split('.')[1]
            filename = f'{uuid.uuid4()}.{ext}'
            with open(static_filepath + "/" + filename, 'wb') as f:
                for i in file.readlines():
                    f.write(i)
            res = {
                'status': 200,
                'text': filename
            }
        except Exception as e:
            res = {
                'status': 201,
                'text': "上传出错！"
            }

    return HttpResponse(json.dumps(res), content_type='application/json')
