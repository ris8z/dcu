#!/usr/bin/env python3

import sys

namefile = sys.argv[1]

with open(namefile, 'w') as f:
    f.write('Hello world.\n')
