#!/usr/bin/env python3

"""
Write a function q1_sum() that takes a list
as input and returns the sum of all even elements.
"""

def q1_sum(array):
    if not array:
        return 0

    if type(array[0]) is list:
        n = q1_sum(array[0])
    else:
        n = array[0]

    if n % 2 != 0:
        n = 0

    return n + q1_sum(array[1:])

print(q1_sum([[1, 0, 2], [5, 5, 7], [9, 4, 3]]))
