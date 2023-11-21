#!/usr/bin/env python3

import os

jobs = ["."]

while jobs:
    Dir = jobs.pop()
    files = os.listdir(Dir)
    i = 0
    while i < len(files):
        file = files[i]
        regular = file[0] != "."
        is_file = os.path.isfile(Dir + "/" + file)
        is_dir = os.path.isdir(Dir + "/" + file)

        if regular and is_file:
            print(Dir + "/" + file)
        if regular and is_dir:
            jobs.append(Dir + "/" + file)

        i += 1
