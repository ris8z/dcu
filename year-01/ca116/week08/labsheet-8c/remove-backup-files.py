#!/usr/bin/env python3

import os

files = os.listdir(".")

i = 0
while i < len(files):
    file = files[i]
    regular_file = file[0] != "." and os.path.isfile(file)
    end_in_bak = file.split(".")[-1] == "bak"

    if regular_file and end_in_bak and file != "bak":
        os.unlink(file)
    i += 1
