from django.conf.urls import url
from movierecommendation import views

urlpatterns = [
    # 主页：豆瓣电影推荐
    url(r'^$', views.doubanRecommendation, name='doubanRecommendation'),

    # 问答页面
    url(r'^questionAnswering/$', views.questionAnswering, name='questionAnswering'),

    # 建立倒排索引
    url(r'^buildindex/$', views.buildindex, name='buildindex'),

    # 精确检索 & 索引检索接口
    url(r'^searchanswer/$', views.searchanswer, name='searchanswer'),

    # DeepSeek API 调用接口
    url(r'^deepseekanswer/$', views.deepseekanswer, name='deepseekanswer'),
]
