#!/usr/bin/env python3

"""
Write a python script named even-value-or-zero.py which reads an integer (
n
, say) and:

    if 
    n
     is even, then outputs the value 
     n
     , or

     if 
     n
      is odd, then outputs just 
      0
      .
approch:
-if a number is odd we want to print zero we can just do n * ((n remainder by 2) - 1)
-bc remainder by two is going to be 1, then we subtract 1 and we get n * 0

-but what we get if the number is even? lets try with our formula
-n * (n % 2 - 1)
-let be n = 4   we get--->  4 * (0 - 1) = -4
-so we get the opposite of what we want, we can just multiply everything by -1 to fix this
-we are not going to messing up the odd part bc is going to be 0 * (-1) that is still 0

-so our formula is ---> n * (n % 2 - 1) * (-1)
"""
n = int(input())

output = -n * (n % 2 - 1)

print(output)
