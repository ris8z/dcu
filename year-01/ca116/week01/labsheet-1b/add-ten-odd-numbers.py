#!/usr/bin/env python3

"""
Standard input consists of exactly ten integers, one per line.

Write a python script named add-ten-odd-numbers.py 
which writes the sum of just the odd numbers to standard output.

it is just the sequal of the ex: week01 - labsheet1a - odd-value-or-zero.py

approach:(of the past exercise)
    -we dont use if statement

    -if a number is even its remainder divided by 2 is going to be zero

    -if a number is odd its remainder divided by 2 is going to be 1

    -we can just output the number times its remainder divided by 2

approach:(of the current one)
    -in fact we want just to do that calculation 10 times and each times add the value a var tot
"""
tot = 0

tmp = int(input())
tot += tmp * (tmp % 2)
tmp = int(input())
tot += tmp * (tmp % 2)
tmp = int(input())
tot += tmp * (tmp % 2)
tmp = int(input())
tot += tmp * (tmp % 2)
tmp = int(input())
tot += tmp * (tmp % 2)
tmp = int(input())
tot += tmp * (tmp % 2)
tmp = int(input())
tot += tmp * (tmp % 2)
tmp = int(input())
tot += tmp * (tmp % 2)
tmp = int(input())
tot += tmp * (tmp % 2)
tmp = int(input())
tot += tmp * (tmp % 2)

print(tot)
