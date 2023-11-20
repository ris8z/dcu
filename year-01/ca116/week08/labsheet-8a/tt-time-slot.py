#!/usr/bin/env python3

line = input()
while line != "end":
    tokens = line.split()
    start = int(tokens[1])
    duration = int(tokens[2])
    end = ((start + duration - 1) % 24)

    timeline = " " + str(start) + ":00 " + str(end) + ":50 "
    day = tokens[0]
    otherdetails = " ".join(tokens[3:])
    print(day + timeline + otherdetails)
    line = input()
