from django.db import models

# Create your models here.
class Book(models.Model):
    id = models.AutoField(primary_key = True)
    year = models.IntegerField()
    author = models.TextField()
    price = models.DecimalField(max_digits = 8, decimal_places = 2)
    title = models.TextField()
    description = models.TextField()
