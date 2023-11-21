#!/usr/bin/env python3

import sys

filenames = sys.argv[1:]

result = 0

i = 0
while i < len(filenames):
    filename = filenames[i]
    with open(filename, 'r') as f:
        numbers = f.read().split()
    j = 0
    while j < len(numbers):
        n = int(numbers[j])
        result += n
        j += 1
    i += 1

print(result)
