#!/usr/bin/env python3
"""
TASK:
 Standard input consists of a month number and a day-of-the-month number, one per line (as above).
 Further, assume that the first day of the first month of the year is a Monday.
 Write a python script named day-of-the-week.py which writes the day of the week to standard output.

 input
 2
 12
 output
 7

 EXPLANATION:
  The 12th day of the second month is the 42nd day of the year.
  If the first day of the year is a Monday, then the 42nd day of the year is a Sunday, so 7.

CONTEXT:


Thinking process:
we want this:(these are the first two weeks of the year)
1 --> 1
2 --> 2
3 --> 3
4 --> 4
5 --> 5
6 --> 6
7 --> 7

8 --> 1
9 --> 2
10 --> 3
11 --> 4
12 --> 5
13 --> 6
14 --> 7

we want 7 outputs that cicles
so we need to use % 7
so our outputs is goning to be {0, 1, 2, 3, 4, 5, 6}
0 is going to be monday, 1 tusday ecc ...
we need to add 1 to get the output in the right way so 1 is monday, 2 tusday ecc..
so our output is going to be something like
output = (something % 7) +  1
-------------------------------------------------
if we just use day_of_year % 7 
let --> = % 7

1 --> 1
2 --> 2
3 --> 3
4 --> 4
5 --> 5
6 --> 6
7 --> 0

8 --> 1
9 --> 2
10 --> 3
11 --> 4
12 --> 5
13 --> 6
14 --> 0

we start from 1 but we want to start from 0 to fit the rule of % seven
-------------------------------------------------

if we consider think 1 <= day_of_year <= 360 we can add -1 to each side
so                   0 <= day_of_year - 1 <= 359

something is going to be (day_of_year - 1)

let's try to use the % 7 on this: (day_of_year - 1) % 7

1 - 1 = 0 --> 0
2 - 1 = 1 --> 1
3 - 1 = 2 --> 2
4 - 1 = 3 --> 3
5 - 1 = 4 --> 4
6 - 1 = 5 --> 5
7 - 1 = 6 --> 6

8 - 1 = 7 --> 0
9 - 1 = 8 --> 1
10 - 1 = 9 --> 2
11 - 1 = 10 --> 3
12 - 1 = 11 --> 4
13 - 1 = 12 --> 5
14 - 1 = 13 --> 6

-------------------------------------------------
now we just need to 1 to the output to get the right one

output = ((day_of_year - 1) % 7) +  1
-------------------------------------------------
"""

month = int(input())
day = int(input())

day_of_year = (month - 1) * 30 + day
day_of_week = ((day_of_year - 1) % 7) + 1
print(day_of_week)
