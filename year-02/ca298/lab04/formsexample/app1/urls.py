from django.urls import path
from . import views

urlpatterns = [
    path('', views.index, name='index'),
    path('employees', views.employees, name='employees'),
    path('createemployees', views.create_employee, name='newemp'),
    path('edit_employee/<int:empid>', views.edit_emp, name='edit'),
]
