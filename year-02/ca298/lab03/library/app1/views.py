from django.http import HttpResponse
from django.shortcuts import render
from .models import *
from django.shortcuts import get_object_or_404

# Create your views here.
def index(request):
    return render(request, 'index.html')

def books(request):
    all_books = Book.objects.all()
    return render(request, 'books.html', {'books': all_books})

def singlebook(request, bookid):
    single_book = get_object_or_404(Book, id = bookid)
    return render(request, 'singlebook.html', {'book': single_book})

def bookbyyear(request, yearid):
    books = Book.objects.filter(year=yearid)
    return render(request, 'bookbyyear.html', {'books': books})

def year(request):
    all_years = Book.objects.order_by('year').values_list('year', flat=True).distinct()
    return render(request, 'year.html', {'years': all_years})

def bookbycategory(request, categoryid):
    books = Book.objects.filter(category=categoryid.upper())
    return render(request, 'bookbycategory.html', {'books': books})

def category(request):
    all_category = Book.objects.order_by('category').values_list('category', flat=True).distinct()
    return render(request, 'category.html', {'category': all_category})

def bookbycategoryandyear(request, categoryid, yearid):
    books = Book.objects.filter(category=categoryid.upper(), year=yearid)
    return render(request, 'bookbycategoryandyear.html', {'books': books})

def cy(request):
    all_cy = Book.objects.order_by('year', 'category').values_list('year', 'category').distinct()
    return render(request, 'categoryandyear.html', {'yc': all_cy})
