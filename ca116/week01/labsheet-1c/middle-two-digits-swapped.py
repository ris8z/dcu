#!/usr/bin/env python3

"""
TASK:
 Repeat the previous task. This time, however, the order of the middle two digits must be swapped.
 Name your script middle-two-digits-swapped.py.

THINKING:
 same solution as before and we get the middile_two_digit
 it's a two digit number 

 the first digit = n // 10
 last one = n % 10

 we can combine them in a new number
 newnumber = lastone * 10 + thefirstdigit * 1
"""

n = int(input())
middile_two_digit = (n // 100) % 100

first = middile_two_digit // 10
last = middile_two_digit % 10

mtdSwapped = last * 10 + first * 1
print(mtdSwapped)
