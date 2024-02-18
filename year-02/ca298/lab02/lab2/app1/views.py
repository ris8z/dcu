from django.http import HttpResponse
from django.shortcuts import render
import random

def index(request):
    return render(request, 'index.html')

def sum(request):
    x = 5
    y = 1
    z = x + y
    return render(request, 'sum.html', {'x': x, 'y': y, 'z': z})

def ifelse(request):
    x = random.randint(0,101)
    return render(request, 'ifelse.html', {'x':x})

def ex2(request):
    numbers = list(range(0,31))
    return render(request, 'ex2.html', {'numbers' : numbers})

def fizzbuzz(request):
    numbers = list(range(0,101))
    return render(request, 'fizzbuzz.html', {'numbers' : numbers})
