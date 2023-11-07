#!/usr/bin/env python3

"""
example:
    926

    -926 % 10 = 6 -> the third digt
    then we cat the last digit by dividing the number by 10 --->926 // 10 = 92

    -(926 // 10) % 10 = 92 % 10 = 2 -> the second digit
    we cat two digits from n by dividing by 100  ---> 926 // 100 = 9

    -(926 // 100) % 10 = 9 % 10 = 9 -> the first digit

    -we save this value in 3 vars and just print them in the right order
"""
n = int(input())

third_digit = (n // 1) % 10
second_digit = (n // 10) % 10
first_digit = (n // 100) % 10

"""
this is another way:

first_digit = (n % 1000) // 100
second_digit = (n % 100) // 10
third_digit = (n % 10) // 1
"""

print(first_digit)
print(second_digit)
print(third_digit)
