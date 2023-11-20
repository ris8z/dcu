#!/usr/bin/env python3

hours = 0
line = input()
while line != "end":
    hours += int(line.split()[2])
    line = input()
print(hours)
