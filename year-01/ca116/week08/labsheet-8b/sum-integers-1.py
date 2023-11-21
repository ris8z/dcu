#!/usr/bin/env python3

import sys

lines = sys.stdin.readlines()
result = 0

i = 0
while i < len(lines):
    line = lines[i].strip()
    n = int(line)
    result += n
    i += 1
print(result)
