#!/usr/bin/env python3

"""
CONTEXT:
 One generation back you have your parents; you have two of those.
 Two generations back you have your grandparents, you have four of those.
 And so on.
TASK:
 Standard input consists of a single positive integer, a number of generations.
 Write a python script named ancestor-count.py which and outputs the number 
 of ancestors you have that many generations back.
THINIKING PROCESS:

1 = 2 = 2         = 2 ** 1
2 = 4 = 2 * 2     = 2 ** 2
3 = 8 = 2 * 2 * 2 = 2 ** 3

it's an exponetial growth
the answer is just 2 to the power of the number of generation

"""

gen = int(input())
output = 2 ** gen
print(output)
