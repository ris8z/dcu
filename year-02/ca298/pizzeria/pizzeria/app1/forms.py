from django.contrib.auth.forms import UserCreationForm
from django import forms
from django.forms import ModelForm, ModelChoiceField
from .models import *
from django.db import transaction
from datetime import datetime
from django.contrib.auth.forms import AuthenticationForm

class UserSignupForm(UserCreationForm):
    class Meta(UserCreationForm.Meta):
        model = User

    @transaction.atomic
    def save(self):
        user = super().save(commit=False)
        user.is_admin = False
        user.email = self.cleaned_data['username']
        user.save()
        return user

class UserLoginForm(AuthenticationForm):
    def __init__(self, *args, **kwargs):
        super(UserLoginForm, self).__init__(*args, **kwargs)

class PizzaForm(forms.ModelForm):
    class Meta:
        model = Pizza
        fields = [
            'size',
            'crust',
            'cheese',
            'sauces',
            'pepperoni',
            'chicken',
            'ham',
            'pineapple',
            'peppers',
            'mushrooms',
        ]

class DeliveryDetailForms(forms.ModelForm):
    class Meta:
        model = DeliveryDetail
        fields = [
            'fname',
            'lname',
            'address',
            'cardnumber',
            'card_expiry_month',
            'card_expiry_year',
            'card_cvv',
        ]

    def clean(self): 
        data = self.cleaned_data

        data['fname'] = data['fname'].lower().capitalize()
        data['lname'] = data['lname'].lower().capitalize()
        data['address'] = data['address'].lower()

        cardnumber = data['cardnumber']
        card_expiry_month = data['card_expiry_month']
        card_expiry_year = data['card_expiry_year']
        card_cvv = data['card_cvv']

        if not cardnumber.isdigit():
            raise forms.ValidationError("A card number must be composed only by digts")
        elif len(cardnumber) != 16:
            raise forms.ValidationError("A card number has 16 digits")
            
        if card_expiry_month not in list(range(1,13)):
            raise forms.ValidationError("A month can only be a number between 1-12") 

        curr_year = datetime.now().year
        curr_month = datetime.now().month

        if card_expiry_month + (card_expiry_year * 12) < curr_month + (curr_year * 12):
            raise forms.ValidationError("Expired card error")

        if not card_cvv.isdigit():
            raise forms.ValidationError("A cvv number must be composed only by digts")
        elif len(card_cvv) != 3 and len(card_cvv) != 4:
            raise forms.ValidationError("A cvv number must be 3 or 4 digits long")

        return data