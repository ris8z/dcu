#!/usr/bin/env python3

"""
TASK:
 Standard input consists of a single six-digit number.
 Write a python script named middle-two-digits.py which writes only the middle two digits to standard output.

 input
 876345
 output
 63

THINKING:

 let be n = 123456
 we want output = 34
 we can cut the last two digit by taking interger division by 100
 so n = n // 100 = 123456 // 100 = 1234
 now to print the last two digits of a 4 digits number we can just use % 100
 n % 100 = 1234 % 100 = 34

 formula
 output = (n // 100) % 100
"""

n = int(input())
middile_two_digits = (n // 100) % 100
print(middile_two_digits)
