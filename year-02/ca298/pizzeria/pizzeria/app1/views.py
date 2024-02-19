from django.http import HttpResponse
from django.shortcuts import render, get_object_or_404
from .forms import *

from django.views.generic import CreateView
from django.shortcuts import redirect
from django.contrib.auth import login, logout
from django.contrib.auth.views import LoginView
from django.contrib.auth.decorators import login_required #you can use @login_required to lock off certain views and require logged in users 

def index(request):
    return render(request, 'index.html')

class UserSignupView(CreateView):
    model = User
    form_class = UserSignupForm
    template_name = 'user_signup.html'

    def get_context_data(self, **kwargs):
        return super().get_context_data(**kwargs)

    def form_valid(self, form):
        user = form.save()
        login(self.request, user)
        return redirect('my_orders') #when an account is registred redirect to the my_ordecrs page default is #return redirect('/')

class UserLoginView(LoginView):
    template_name='login.html'

def logout_user(request):
    logout(request)
    return redirect("/")

@login_required
def fill_pizza(request):
    if request.method != "POST":
        form = PizzaForm()
        return render(request, 'fill_pizza.html', {'form': form})
    
    form = PizzaForm(request.POST)
    if not form.is_valid():
        return render(request, 'fill_pizza.html', {'form': form})

    pizza_obj = form.save()
    
    return redirect("fill_detail", pizzaid=pizza_obj.id)

@login_required
def fill_detail(request, pizzaid):
    pizza_obj = get_object_or_404(Pizza, id=pizzaid)

    if request.method != "POST":
        form = DeliveryDetailForms()
        return render(request, 'fill_detail.html', {'form': form})

    form = DeliveryDetailForms(request.POST)
    if not form.is_valid():
        return render(request, 'fill_detail.html', {'form': form})
    
    detail_obj = form.save()
    curr_user = request.user
    newPizzaUser = PizzaUser.objects.create(pizza=pizza_obj, detail=detail_obj, user=curr_user)
    newPizzaUser.save()

    return render(request, 'thanks.html', {'order': newPizzaUser})

@login_required
def my_orders(request):
    user = request.user
    orders = PizzaUser.objects.filter(user=user)
    return render(request, 'my_orders.html', {'orders': orders})