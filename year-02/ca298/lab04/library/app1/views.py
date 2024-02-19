from django.http import HttpResponse
from django.shortcuts import render
from .models import *
from django.shortcuts import get_object_or_404
from .forms import *

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

def add_book(request):
    if request.method != "POST":
        #the user want to see the from
        form = BookForm()
        return render(request, 'add_book.html', {'form': form})

    #the user is sending the form
    form = BookForm(request.POST)
    if not form.is_valid():
        #we give the form back to the user
        return render(request, 'add_book.html', {'form': form})

    #here we know that the form is valid
    book = form.save()
    return render(request, 'created_book.html', {'book': book})

def edit_book(request, bookid):
    book = get_object_or_404(Book, id=bookid)

    if request.method != "POST":
        #vuole vedere il form
        form = BookForm(instance=book)
        return render(request, 'edit_book.html', {'form': form})

    #ci sta mandando il form
    form = BookForm(request.POST, instance=book)
    if not form.is_valid():
        #ci sono degli errori gli mandiamo back il form
        return render(request, 'edit_book.html', {'form': form})
    #qui sappiamo che il form e' valido
    form.save()
    return render(request, 'edited_book.html', {'book': book})










