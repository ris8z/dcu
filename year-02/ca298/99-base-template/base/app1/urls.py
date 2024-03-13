from django.urls import path
from . import views
from .forms import *

urlpatterns=[
  path('', views.index, name='index'),
  path('page2', views.page2, name='page2'),
  path('register/', views.UserSignupView.as_view(), name="register"),
  path('login/',views.LoginView.as_view(template_name="login.html", authentication_form=UserLoginForm), name='login'),
  path('logout/', views.logout_user, name="logout"),
]