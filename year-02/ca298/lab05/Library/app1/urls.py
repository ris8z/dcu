from django.urls import path
from . import views

#lab 05 imports
from django.urls import include
from rest_framework import routers
router = routers.DefaultRouter()
router.register(r'customer', views.CustomerViewSet)
#---------------

urlpatterns = [
    path('', views.index, name='index'),
    path('books', views.all_books, name='all_books'),
    path('books/<int:bookid>', views.singlebook, name='singlebook'),
    path('customers', views.all_customers, name='all_customers'),
    path('customers/<int:customerid>', views.single_customer, name='singlecustomer'),
    
    #lab 05
    path('add', views.api_add, name='api_add'),
    path('subtract', views.api_subtract, name='api_subtract'),
    path('divide', views.api_divide, name='api_divide'),
    path('multiply', views.api_multiply, name='api_multiply'),
    path('exponential', views.api_exponential, name='api_exponential'),

    path('api/', include(router.urls)), # add the router to our urls
]
