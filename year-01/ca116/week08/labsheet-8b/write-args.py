#!/usr/bin/env python3

import sys

namefile = sys.argv[1]
words = sys.argv[2:]

with open(namefile, 'w') as f:
    i = 0
    while i < len(words):
        word = words[i]
        f.write(word + '\n')
        i = i + 1
