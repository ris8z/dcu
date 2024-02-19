from django.db import models
from django.contrib.auth.models import AbstractUser, BaseUserManager #creating a user model
    
class UserManager(BaseUserManager):
    """Define a model manager for User model with no username field."""

    use_in_migrations = True

    def _create_user(self, email, password, **extra_fields):
        """Create and save a User with the given email and password."""
        if not email:
            raise ValueError('The given email must be set')
        email = self.normalize_email(email)
        user = self.model(email=email, **extra_fields)
        user.set_password(password)
        user.save(using=self._db)
        return user

    def create_user(self, email, password=None, **extra_fields):
        """Create and save a regular User with the given email and password."""
        extra_fields.setdefault('is_staff', False)
        extra_fields.setdefault('is_superuser', False)
        return self._create_user(email, password, **extra_fields)

    def create_superuser(self, email, password, **extra_fields):
        """Create and save a SuperUser with the given email and password."""
        extra_fields.setdefault('is_staff', True)
        extra_fields.setdefault('is_superuser', True)

        if extra_fields.get('is_staff') is not True:
            raise ValueError('Superuser must have is_staff=True.')
        if extra_fields.get('is_superuser') is not True:
            raise ValueError('Superuser must have is_superuser=True.')

        return self._create_user(email, password, **extra_fields)

class User(AbstractUser):
    email = models.EmailField('Email', unique=True)
    USERNAME_FIELD = 'email'
    REQUIRED_FIELDS = []
    objects = UserManager()

class PizzaSize(models.Model):
    id = models.AutoField(primary_key=True)
    name = models.TextField()
    def __str__(self):
        return self.name

class CheeseType(models.Model):
    id = models.AutoField(primary_key=True)
    name = models.TextField()
    def __str__(self):
        return self.name

class SaucesType(models.Model):
    id = models.AutoField(primary_key=True)
    name = models.TextField()
    def __str__(self):
        return self.name

class Pizza(models.Model):
    id = models.AutoField(primary_key=True)

    #foreignkeys
    size = models.ForeignKey(PizzaSize, on_delete=models.CASCADE)
    cheese = models.ForeignKey(CheeseType, null=True, on_delete=models.CASCADE)
    sauces = models.ForeignKey(SaucesType, null=True, on_delete=models.CASCADE)
    
    #multiple choices
    crust_choices = [
        ('normal', 'normal'),
        ('thin', 'thin'),
        ('gluten-free', 'gluten-free'),
    ]
    crust = models.CharField(max_length=50, choices=crust_choices, default='normal')

    #boolean fields
    pepperoni = models.BooleanField(default=False)
    chicken = models.BooleanField(default=False)
    ham = models.BooleanField(default=False)
    pineapple = models.BooleanField(default=False)
    peppers = models.BooleanField(default=False)
    mushrooms = models.BooleanField(default=False)
    onions = models.BooleanField(default=False)

class DeliveryDetail(models.Model):
    id = models.AutoField(primary_key=True)
    fname = models.CharField(max_length=30)
    lname = models.CharField(max_length=30)
    address = models.CharField(max_length=30)
    cardnumber = models.CharField(max_length=16)
    card_expiry_month = models.IntegerField()
    card_expiry_year = models.IntegerField()
    card_cvv = models.CharField(max_length=4)

class PizzaUser(models.Model):
    id = models.AutoField(primary_key=True)
    pizza = models.ForeignKey(Pizza, on_delete=models.CASCADE)
    detail = models.ForeignKey(DeliveryDetail, on_delete=models.CASCADE, null=True, default=None)
    user = models.ForeignKey(User, on_delete=models.CASCADE)
    date_ordered = models.DateTimeField(auto_now_add=True)