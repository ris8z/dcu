from django.urls import path
from . import views

urlpatterns = [
    path('', views.index, name='index'),
    path('books', views.books, name='books'),
    path('books/<int:bookid>', views.singlebook, name='singlebook'),
]
