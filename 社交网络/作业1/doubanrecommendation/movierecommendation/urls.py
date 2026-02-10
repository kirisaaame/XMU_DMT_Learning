from django.conf.urls import url
from movierecommendation import views

urlpatterns = [
    url(r'^$', views.doubanRecommendation, name='doubanRecommendation'),
    url(r'^questionAnswering', views.questionAnswering, name='questionAnswering'),
    url(r'^questionAnswering/$', views.questionAnswering, name='questionAnswering'),
]
