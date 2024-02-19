from django import forms
from .models import *


class EmployeesForm(forms.ModelForm):
    class Meta:
        model = Employee # picked from the models.py
        fields = ['f_name', 'l_name', 'department']
    def clean(self):
        
        data = self.cleaned_data
        fname = data['f_name']
        lname = data['l_name']

        emp_exists = Employee.objects.filter(f_name=fname, l_name=lname).exists()

        #Se self.instance.pk è None, significa che il form sta per creare una nuova istanza
        if emp_exists and  self.instance.pk == None:
            raise forms.ValidationError("An employee of that name already exists")
        return data
