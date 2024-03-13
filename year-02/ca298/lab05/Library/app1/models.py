from django.db import models

# Create your models here.
class Book(models.Model):
  id = models.AutoField(primary_key=True)
  title = models.TextField(default='Libro')
  author = models.TextField()
  genere = models.TextField()
  year = models.IntegerField()
  n_inv = models.IntegerField()

class Customer(models.Model):
  id = models.AutoField(primary_key=True)
  name = models.TextField()

class Borrowing(models.Model):
  id = models.AutoField(primary_key=True)
  book = models.ForeignKey(Book, on_delete=models.CASCADE)
  customer = models.ForeignKey(Customer, on_delete=models.CASCADE)
  is_returned = models.BooleanField(default=False)

