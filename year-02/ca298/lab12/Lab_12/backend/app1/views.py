from django.http import HttpResponse
from django.shortcuts import get_object_or_404
from django.shortcuts import render
from .models import *

# Create your views here.
def index(request):
    return render(request, 'index.html')

def all_books(request):
    books = Book.objects.all() 
    return render(request, 'all_books.html', {'books':books})

def singlebook(request, bookid):
    book_obj = get_object_or_404(Book, id=bookid)
    borrowings = Borrowing.objects.filter(book=book_obj, is_returned=False)
    return render(request, 'singlebook.html', {'book': book_obj, 'borrowings': borrowings})

def all_customers(request):
    customers = Customer.objects.all()
    return render(request, 'all_customers.html', {'customers':customers})

def single_customer(request, customerid):
    customer_obj = get_object_or_404(Customer, id=customerid)
    p_borrowing = Borrowing.objects.filter(customer=customer_obj, is_returned=True)
    c_borrowing = Borrowing.objects.filter(customer=customer_obj, is_returned=False)
    return render(request, 'singlecustomer.html', {'customer': customer_obj, 'P_borrowings': p_borrowing, 'C_borrowings': c_borrowing})

#lab 05 <-----------------------------------
from django.http import JsonResponse # import the jsonresponse object

# assumes get parameters 
# num1 and num2
# e.g. http://127.0.0.1:8000/add?num1=5&num2=6 returns 11
def api_add(request):
	# use 1 as default
	# we should enforce type restriction by casting the value passed to a float
	# they are assumed strings by default
	# see how to cast here: https://www.w3schools.com/python/python_casting.asp
	num1 = float(request.GET.get('num1',1)) 
	num2 = float(request.GET.get('num2',1))
	added = num1 + num2 # calculate the added value
	# prepare a dict to return as a json response
    # we have to give the value 'added' a key we will call 'result'
	resp_dict = {'result':added}
	return JsonResponse(resp_dict) # return the dict as a json respone

def api_subtract(request):
    num1 = float(request.GET.get('num1', 1))
    num2 = float(request.GET.get('num2', 1))
    result = num1 - num2
    resp_dict = {'result':result}
    return JsonResponse(resp_dict)

def api_divide(request):
    num1 = float(request.GET.get('num1', 1))
    num2 = float(request.GET.get('num2', 1))
    result = num1 / num2
    resp_dict = {'result':result}
    return JsonResponse(resp_dict)

def api_multiply(request):
    num1 = float(request.GET.get('num1', 1))
    num2 = float(request.GET.get('num2', 1))
    result = num1 * num2
    resp_dict = {'result':result}
    return JsonResponse(resp_dict)

def api_exponential(request):
    num1 = float(request.GET.get('num1', 1))
    num2 = float(request.GET.get('num2', 1))
    result = num1 ** num2
    resp_dict = {'result':result}
    return JsonResponse(resp_dict)


#views.py

## add the following imports
from rest_framework import viewsets
from .models import *
from .serializers import *

## viewset for customers
class CustomerViewSet(viewsets.ModelViewSet):
	serializer_class = CustomerSerializer
	queryset = Customer.objects.all()

## viewset for books
class BookViewSet(viewsets.ModelViewSet):
    serializer_class = BookSerializer
    queryset = Book.objects.all()