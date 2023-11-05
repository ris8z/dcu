#!/usr/bin/env python3

"""
TASK:
 Standard input consists of a single two-digit integer.
 Write a python script named sum-both-digits.py which writes the sum of the two digits to standard outpu

 input
 72
 output
 9

THINKING:
 we just split the number and take the sum
 first digit = n // 10
 last digit = n % 10

 output = firstdigit + lastdigit
"""

n = int(input())
first = n // 10
last = n % 10
output = first + last
print(output)
