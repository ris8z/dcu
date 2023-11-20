#!/usr/bin/env python3

line = input()
while line != "end":
    print(" ".join(line.split()[5:]))
    line = input()
