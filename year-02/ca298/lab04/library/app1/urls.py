from django.urls import path
from . import views

urlpatterns = [
    path('', views.index, name='index'),
    path('books', views.books, name='books'),
    path('books/<int:bookid>', views.singlebook, name='singlebook'),
    path('books/year', views.year, name='year'),
    path('books/year/<int:yearid>', views.bookbyyear, name='bookbyyear'),
    path('books/category', views.category, name='category'),
    path('books/category/<str:categoryid>', views.bookbycategory, name='bookbycategory'),
    path('books/category_year', views.cy, name='cy'),
    path('books/category/<str:categoryid>/year/<int:yearid>', views.bookbycategoryandyear, name='bookbycategoryandyear'),
    path('add_book', views.add_book, name='add_book'),
    path('editbook/<int:bookid>', views.edit_book, name='editbook'),
]
