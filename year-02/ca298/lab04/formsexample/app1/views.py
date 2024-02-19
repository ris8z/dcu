from django.http import HttpResponse
from django.shortcuts import render, get_object_or_404
from .models import *
from .forms import *

# Create your views here.
def index(request):
    return render(request, 'index.html')

def employees(request):
    all_emp = Employee.objects.all()
    return render(request, 'employees.html', {'employees': all_emp})

def create_employee(request):
    if request.method == "POST":
        form = EmployeesForm(request.POST)

        if form.is_valid():
            emp = form.save()
            return render(request, 'created.html', {'emp':emp})
        else:
            return render(request, 'create_emp.html', {'form': form})
    else:
        form = EmployeesForm()
        return render(request, 'create_emp.html', {'form': form})

def edit_emp(request, empid):

    emp = get_object_or_404(Employee, id=empid)

    if request.method == "POST":
        form = EmployeesForm(request.POST, instance=emp)

        if form.is_valid():
            form.save()
            return render(request, 'updated_edit.html', {'emp': emp})
        else:
            return render(request, 'edit_emp.html', {'form': emp})
    else:
        form = EmployeesForm(instance=emp)
        return render(request, 'edit_emp.html', {'form': form})
        
            
