from django.shortcuts import render, redirect
from django.http import HttpResponse 
# Create your views here.
from .forms import *
from django.contrib.auth import login, logout
from django.views.generic import CreateView
from django.contrib.auth.views import LoginView

def index(request):
  return render(request, 'index.html')

def page2(request):
  return render(request, 'page2.html')


#register views
class UserSignupView(CreateView):
    model = User
    form_class = UserSignupForm
    template_name = 'user_signup.html'

    def get_context_data(self, **kwargs):
        return super().get_context_data(**kwargs)

    def form_valid(self, form):
        user = form.save()
        login(self.request, user)
        return redirect('/')

#login views
class UserLoginView(LoginView):
    template_name='login.html'


def logout_user(request):
    logout(request)
    return redirect("/")