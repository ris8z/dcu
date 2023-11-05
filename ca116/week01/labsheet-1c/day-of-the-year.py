#!/usr/bin/env python3

"""
Context:

 imagine an alternative world in which a year consists of 12 months, 
 as normal, but every month consists of exactly 30 days.

 Months are numbered from 1 to 12
 and days from 1 to 30
 A week has seven days, as usual.
 Week days start on a Monday, and are numbered 1 to 7.

Task:

 Standard input consists of two integers, one per line: a month number and a day-of-the-month number.
 Write a python script named day-of-the-year.py which writes the day of the year to standard output.

 The days of the year are numbered from 1 to 360.

Example:

 day/month
 12/1 -->should be the 12th day of the year
 1/2  -->should be the 31th day of the year

Approach:
 let a = month
 let b = day
 
 our output is the sum of the current day plus the number of month passed in days
 output = b + (number of month passed in days)

 let c = number of month passed in days
 c is equal to the number of month * 30, but we dont need to count the current month, in fact
 12/1 is the 12th day of the year and not the (12 + 30)th, so
 c = (number of month - 1) * 30
 c = (a - 1) * 30

 our output is:
 output = b + (a - 1) * 30

"""
month = int(input())
day = int(input())

day_of_the_year = (month - 1) * 30 + day
print(day_of_the_year)
