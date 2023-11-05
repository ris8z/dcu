#!/usr/bin/env python3

"""
TASK:
 Standard input consists of exactly three digits, one per line. Take these to be, respectively,
 the first, second and third digits of a three-digit number.
 Write a python script named three-digit-number.py which writes that number to standard output.

 input
 7
 3
 5
 output
 738
THINKING:
 we can take advantage of the fact that we know how many digits has the number
 the first digit would be the one that raprestents the hundreds of our final number

 tot = 0
 tot = tot + (firstdigit * 100)

 the second the  decine
 tot = tot + (seconddigit * 10)

 the last one the unit
 tot = tot + (lastdigit * 1)
"""

first = int(input())
second = int(input())
last = int(input())

output = first * 100 + second * 10 + last * 1
print(output)
