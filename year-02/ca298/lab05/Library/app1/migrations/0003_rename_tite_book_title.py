# Generated by Django 5.0.2 on 2024-02-23 15:07

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('app1', '0002_book_tite'),
    ]

    operations = [
        migrations.RenameField(
            model_name='book',
            old_name='tite',
            new_name='title',
        ),
    ]