# Generated by Django 5.0.2 on 2024-02-21 07:38

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('app1', '0010_pizzauser_arrived_time'),
    ]

    operations = [
        migrations.RemoveField(
            model_name='pizzauser',
            name='arrived_time',
        ),
    ]
