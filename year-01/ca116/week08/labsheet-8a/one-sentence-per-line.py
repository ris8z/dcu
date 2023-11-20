#!/usr/bin/env python3

words = []

line = input()
while line != "end":
    words = words + line.split()
    line = input()

text = " ".join(words)
lines = text.split(".")

i = 0
while i < len(lines):
    line = lines[i].strip() + "."
    if line != ".":
        print(line)
    i += 1
