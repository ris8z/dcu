#!/usr/bin/env python3

line = input()
while line != "end":
    if int(line.split()[2]) > 1:
        print(line)
    line = input()
