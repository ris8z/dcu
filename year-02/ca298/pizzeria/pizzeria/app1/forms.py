from django.contrib.auth.forms import UserCreationForm
from django import forms
from django.forms import ModelForm, ModelChoiceField
from .models import *
from django.db import transaction

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

from django.contrib.auth.forms import AuthenticationForm

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