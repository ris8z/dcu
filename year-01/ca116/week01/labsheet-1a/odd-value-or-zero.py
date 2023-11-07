#!/usr/bin/env python3

"""
Write a python script named odd-value-or-zero.py which reads an integer (
n
, say) and:

    if 
    n
     is odd, then outputs the value 
     n
     , or

     if 
     n
      is even, then outputs just 
      0
      .
approach:
-we dont use if statement

-if a number is even its remainder divided by 2 is going to be zero

-if a number is odd its remainder divided by 2 is going to be 1

-we can just output the number times its remainder divided by 2
"""
n = int(input())

output = n * (n % 2)

print(output)
