#!/usr/bin/env python3

import sys

namefileA = sys.argv[1]
namefileB = sys.argv[2]
linesA = []

with open(namefileA, 'r') as f:
    linesA = f.readlines()
linesB = []
with open(namefileB, 'r') as f:
    linesB = f.readlines()
i = 0
found = False
while i < len(linesA) and i < len(linesB) and found is False:
    lineA = linesA[i].strip()
    lineB = linesB[i].strip()
    z = 0
    while z < len(lineA) and z < len(lineB) and (lineA[z] == lineB[z]):
        z += 1
    if z < len(lineA) or z < len(lineB):
        print(i, z)
        found = True
    i += 1
if (i < len(linesA) or i < len(linesB)) and found is False:
    print(i, 0)
