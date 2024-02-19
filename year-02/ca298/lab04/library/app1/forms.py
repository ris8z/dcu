from django import forms
from .models import *
from datetime import datetime

class BookForm(forms.ModelForm):
    class Meta:
        model = Book # picked from  models.py
        fields = ['year', 'author' , 'price' , 'title', 'description', 'category']
    def clean(self):
        
        data = self.cleaned_data
        title = data['title']
        year = data['year']

        book_exists = Book.objects.filter(title=title).exists()

        if book_exists and self.instance.pk == None:
            raise forms.ValidationError("A book with same title already exits")

        curr_year = datetime.now().year
        if year > curr_year:
            raise forms.ValidationError("A book can not be published in the future")

        return data
