# Generated by Django 3.2.12 on 2024-02-19 10:38

from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        ('app1', '0001_initial'),
    ]

    operations = [
        migrations.CreateModel(
            name='CheeseType',
            fields=[
                ('id', models.IntegerField(primary_key=True, serialize=False)),
                ('name', models.TextField()),
            ],
        ),
        migrations.CreateModel(
            name='PizzaSize',
            fields=[
                ('id', models.IntegerField(primary_key=True, serialize=False)),
                ('name', models.TextField()),
            ],
        ),
        migrations.CreateModel(
            name='SaucesType',
            fields=[
                ('id', models.IntegerField(primary_key=True, serialize=False)),
                ('name', models.TextField()),
            ],
        ),
        migrations.CreateModel(
            name='Pizza',
            fields=[
                ('id', models.IntegerField(primary_key=True, serialize=False)),
                ('crust', models.CharField(choices=[('normal', 'normal'), ('thin', 'thin'), ('gluten-free', 'gluten-free')], default='normal', max_length=50)),
                ('pepperoni', models.BooleanField(default=False)),
                ('chicken', models.BooleanField(default=False)),
                ('ham', models.BooleanField(default=False)),
                ('pineapple', models.BooleanField(default=False)),
                ('peppers', models.BooleanField(default=False)),
                ('mushrooms', models.BooleanField(default=False)),
                ('onions', models.BooleanField(default=False)),
                ('cheese', models.ForeignKey(null=True, on_delete=django.db.models.deletion.CASCADE, to='app1.cheesetype')),
                ('sauces', models.ForeignKey(null=True, on_delete=django.db.models.deletion.CASCADE, to='app1.saucestype')),
                ('size', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to='app1.pizzasize')),
            ],
        ),
    ]