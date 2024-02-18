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
