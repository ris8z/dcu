#!/usr/bin/env python3

"""
Write a function sum_q1() that takes an integer
as input and returns the sum of 0...n using recursion.
"""

def sum_q1(n):
    if n == 0:
        return 0
    return n + sum_q1(n - 1)

assert(sum_q1(6) == 21)

"""
Using recursion, write a script to reverse an integer.
"""
def reverse(n, tmp=0):
    if n == 0:
        return tmp

    tmp *= 10
    tmp += n % 10

    return reverse(n // 10, tmp)

assert(reverse(123) == 321)
assert(reverse(256) == 652)

"""
Similar to Q2, write a script to reverse a string using recursion.
"""

def reverse_string(string):
    if string == "":
        return ""
    return string[-1] + reverse_string(string[:-1])

assert(reverse_string("hello") == "olleh")
assert(reverse_string("1234") == "4321")

"""
Write a script to inverse a list of numbers using recursion.
"""

def reverse_list(lst):
    if lst == []:
        return []
    return [lst[-1]] + reverse_list(lst[:-1])

assert(reverse_list([1, 2, 3, 4]) == [4, 3, 2, 1])

"""
Create a function that returns the product of two integers.
This process of multiplication can be achieved via repetitive addition, 
thus, the process can be done recursively. 
"""

"""
Brief approach:

if b > 0 we want to add a b times:
2, 4 = 8
-2, 4 = -8

if b < 0 the result is the same of b positive but with * -1
2, -4 = -8
-2, -4 = 8
"""

def multiply(a, b):
    if a == 0 or b == 0:
        return 0

    if b > 0:    
        return a + multiply(a, b - 1)
    if b < 0:
        return -multiply(a, -b)


assert(multiply(10, 2) == 20)
assert(multiply(-51, -4) == 204)
assert(multiply(3, 9) == 27)

"""
 A pronic number (or otherwise called as heteromecic) is a number 
 which is a product of two consecutive integers,
 that is, a number of the form n(n + 1). 
 Create a function that determines whether a number is pronic or not.
"""
def is_heteromecic(n, a=0, b=1):
    if a * b == n:
        return True
    if a * b > n:
        return False

    return is_heteromecic(n, a + 1, b + 1)

assert(is_heteromecic(110) == True)
assert(is_heteromecic(5 * 6) == True)
assert(is_heteromecic(123 * 124) == True)
assert(is_heteromecic(123 * 2) == False)

"""
 Write a function that returns the length of a string. 
 Make your function recursive.
"""

def string_len(string):
    if string == "":
        return 0
    return 1 + string_len(string[1:])

assert(string_len("hello") == 5)
assert(string_len("hell") == 4)
assert(string_len("hel") == 3)
assert(string_len("123456789") == 9)
