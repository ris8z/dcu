#!/usr/bin/env python3

"""
standard input consists of two integers, one per line:
the first is an initial rabbit population, and the second is a number of years.

Write a python script named rabbits-everywhere.py
which writes the final rabbit population after the indicated number of years to standard output.

example:
 initial_population = 100
 years = 3
 current population = 800

 800 = 100 * (8)
 800 = 100 * (2 * 2 * 2)
 800 = 100 * (2 ** 3)

 current_population = initial_population * (2 ** years)

"""

initial_population = int(input())
years = int(input())
current_population = initial_population * (2 ** years)
print(current_population)
