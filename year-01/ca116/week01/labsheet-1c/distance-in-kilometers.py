#!/usr/bin/env python3

"""
TASK:
 Standard input consists of a single integer, a distance measured in meters.
 Write a python script named distance-in-kilometers.py which writes the 
 corresponding distance in kilometers to standard output.
 Rounding
 Round fractional kilometers of strictly less than 500m down to the nearest kilometers,
 and greater than that up. For example, 7499m becomes 7km whereas 7500 becomes 8km.
 Your solution may not use the python built-in function round().

THINKING PROCESS:
 ex1:
 n = 7499m we need to convert that in m

 we can think about this number as two different part
 
 first digit = is how many real m are counted as km in this case 7
 last 3 digit = if this are >= than 500 we need to add another km to our count else we add 0

 so our pseudo code would be:

 output = first digit
 if (last 3 digit) >= 500:
    output = output + 1
 else:
    output = output + 0

 First question? how we get the first digit and the last 3, it is easy

 first_digit = n // 1000 (just integer divison)
 last_3_digit = n % 1000 (just the moduls operator)

 we really don't need an if statemt bc we need to add one if last_3_digit is > than 500 else 0
 it's just:

 let a = last_3_digit // 500

 a for in every n: 0 <= n <= 499 is going to be 0
 a for in every n: 500 <= n <= 999 is going to be 1

 Our final formula:
  output = first_digit + (last_3_digit // 500)

"""
n = int(input())
first_digit = n // 1000
last_3_digit = n % 1000
n_in_m = first_digit + (last_3_digit // 500)
print(n_in_m)
