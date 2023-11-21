#!/usr/bin/env python3

import os

jobs = ["start.txt"]

while jobs:
    filename = jobs.pop()
    with open(filename, 'r') as f:
        text = f.read().strip()

    if os.path.isfile(text):
        jobs.append(text)
    else:
        print(text)
