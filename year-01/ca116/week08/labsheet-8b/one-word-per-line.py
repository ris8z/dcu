#!/usr/bin/env python3

import sys

text = sys.stdin.read()
text = text.split()
text = "\n".join(text)
print(text)
