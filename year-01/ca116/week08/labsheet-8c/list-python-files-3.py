#!/usr/bin/env python3

import os

files = os.listdir(".")

i = 0
while i < len(files):
    file = files[i]
    if file[0] != ".":
        with open(file, 'r') as f:
            lines = f.readlines()

        is_non_empty = lines != []
        if is_non_empty:
            firstline = lines[0]
            end_in_py = file.split(".")[-1] == "py"
            shebang = firstline.strip() == "#!/usr/bin/env python3"

            if end_in_py or shebang:
                print(file)
    i += 1
