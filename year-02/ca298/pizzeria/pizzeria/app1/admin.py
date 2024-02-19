from django.contrib import admin
from django.contrib.auth.admin import UserAdmin
from .models import *

# Register your models here.
admin.site.register(User, UserAdmin)
admin.site.register(PizzaSize)
admin.site.register(CheeseType)
admin.site.register(SaucesType)
admin.site.register(Pizza)
admin.site.register(PizzaUser)
admin.site.register(DeliveryDetail)