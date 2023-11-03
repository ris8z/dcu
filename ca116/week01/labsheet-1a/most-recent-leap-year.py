#!/usr/bin/env python3

""" 
Task
Standard input consists of a single integer, a year.

Write a python script named most-recent-leap-year.py
which writes the most recent leap year in or before that year to standard output.

For the purpose of this task, assume that any year which is divisible by four is a leap year.

approch:

-because of this semplification the gap between the current year and the most recent leap one is the remainder
of the current year divided by 4
-if the current year is a leap one the gap is going to be zero
-so we just print year - gap

"""

year = int(input())

gap = year % 4

most_recent_year = year - gap

print(most_recent_year)
