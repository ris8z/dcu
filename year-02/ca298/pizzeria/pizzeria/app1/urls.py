from django.urls import path
from . import views
from .forms import *

urlpatterns = [
    path('', views.index, name='index'),
    path('register/', views.UserSignupView.as_view(), name="register"),
    path('login/', views.LoginView.as_view(template_name="login.html", authentication_form=UserLoginForm), name='login'),
    path('logout/', views.logout_user, name="logout"),
    path('fill_pizza', views.fill_pizza, name='fill_pizza'),
    path('my_orders', views.my_orders, name='my_orders'),
    path('fill_detail/<int:pizzaid>', views.fill_detail, name='fill_detail'),
]