from django.urls import path
from . import views


urlpatterns = [
    path('', views.index, name = 'index'),
    path('sum', views.sum, name = 'sum'),
    path('ifelse', views.ifelse, name = 'ifelse'),
    path('ex2', views.ex2, name = 'ex2'),
    path('fizzbuzz', views.fizzbuzz, name = 'fizzbuzz'),
]
