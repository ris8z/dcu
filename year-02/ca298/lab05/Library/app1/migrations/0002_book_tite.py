# Generated by Django 5.0.2 on 2024-02-23 15:04

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('app1', '0001_initial'),
    ]

    operations = [
        migrations.AddField(
            model_name='book',
            name='tite',
            field=models.TextField(default='Libro'),
        ),
    ]
