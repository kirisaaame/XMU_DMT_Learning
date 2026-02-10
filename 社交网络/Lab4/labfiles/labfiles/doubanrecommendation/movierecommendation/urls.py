from django.urls import re_path as url
from movierecommendation import views

urlpatterns = [
    url(r'^questionAnswering', views.questionAnswering, name='questionAnswering'),
    url(r'^searchanswer', views.searchanswer, name='searchAnswer'),
    url(r'^buildindex', views.buildindex, name='questionIndex')
]
