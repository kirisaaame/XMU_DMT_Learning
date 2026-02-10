"""doubanrecommendation URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/4.2/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.urls import re_path as url
from django.conf.urls import include
from django.contrib import admin
from django.contrib.staticfiles.urls import staticfiles_urlpatterns
from movierecommendation import views

urlpatterns = [
    url(r'^questionAnswering', include('movierecommendation.urls')),
    url(r'^admin', admin.site.urls),
    url(r'^$', views.questionAnswering),
    url(r'^searchanswer', views.searchanswer),
    url(r'^buildindex', views.buildindex),
    url(r'^deepseekanswer', views.deepseekanswer),
    url(r'^uploaddatafile', views.uploaddatafile)
]
urlpatterns += staticfiles_urlpatterns()
