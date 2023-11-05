#!/usr/bin/env python3

"""
TASK:
 Standard input consists of exactly three binary digits, one per line. Take these 
 to be, respectively, the first, second and third digits of a three-digit binary number.
 Write a python script named three-digit-binary-number.py which writes 
 that number to standard output in decimal.

 input
 1
 1
 0
 output
 6

THINKING:
 is the same task of before but the position value of the number in binary change

 decimal: (100)    (10)     (1) = (10 ** 2) (10 ** 1) (10 ** 0)
 binary:  (4)      (2)      (1) = (2 ** 2)  (2 ** 1)  (2 ** 0)

 so first digit is going to have a value of 4 of
 second 2
 last 1
"""

first = int(input())
second = int(input())
last = int(input())

n_dec = first * 4 + second * 2 + last * 1
print(n_dec)
