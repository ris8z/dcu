#!/usr/bin/env python3

lines = []

line = input()
while line != "end":
    lines.append(line)
    line = input()

day = input()

i = 0
while i < len(lines):
    line = lines[i]
    if day == line.split()[0]:
        print(line)
    i = i + 1
