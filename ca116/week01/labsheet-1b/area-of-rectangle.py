#!/usr/bin/env python3

"""
Example:

  5
  4
  3   *  *
  2
  1   *  *
  01234567

x1 = 4
y1 = 1

x2 = 7
y2 = 3

base = 7 - 4 = x2 - x1
height = 3 - 1 = y2 - y1

area = base * height = (x2 - x1) * (y2 - y1)

"""

x1 = int(input())
y1 = int(input())
x2 = int(input())
y2 = int(input())

base = x2 - x1
height = y2 - y1
area = base * height
print(area)
