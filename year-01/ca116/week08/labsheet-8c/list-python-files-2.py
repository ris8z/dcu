#!/usr/bin/env python3

import os

files = os.listdir(".")

i = 0
while i < len(files):
    file = files[i]
    if file[0] != "." and file.split(".")[-1] == "py":
        with open(file, 'r') as f:
            text = f.read()
        if text:
            print(file)
    i += 1
