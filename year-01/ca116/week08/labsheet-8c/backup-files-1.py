#!/usr/bin/env python3

import os

files = os.listdir(".")

i = 0
while i < len(files):
    file = files[i]
    if file[0] != "." and file.split(".")[-1] != "bak":
        with open(file, "r") as f_input, open(file + ".bak", "w") as f_output:
            f_output.write(f_input.read())
    i += 1
