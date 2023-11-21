#!/usr/bin/env python3

import sys

filenames = sys.argv[1:]

result = 0
i = 0
while i < len(filenames):
    filename = filenames[i]
    with open(filename, 'r') as f:
        lines = f.readlines()
    j = 0
    while j < len(lines):
        line = lines[j].strip()
        n = int(line)
        result += n
        j += 1
    i += 1

print(result)
