from django.db import models

# Create your models here.

class Department(models.Model):
    id = models.AutoField(primary_key=True)
    name = models.TextField()
    address = models.CharField(max_length=10)

    def __str__(self):
        return "{} - {}".format(self.address, self.name)

class Employee(models.Model):
    id = models.AutoField(primary_key=True)
    f_name = models.CharField(max_length=30)
    l_name = models.CharField(max_length=30)
    department = models.ForeignKey(Department, on_delete=models.CASCADE)
