#!/usr/bin/env python3

lines = []
with open('irish-dobs.txt', 'r') as f:
    lines = f.readlines()


with open('american-dobs.txt', 'w') as f:
    i = 0
    while i < len(lines):
        line = lines[i].strip()

        dob = line.split()[0]
        name = " ".join(line.split()[1:])

        day, month, year = dob.split("/")
        newdob = month + "/" + day + "/" + year

        newline = newdob + " " + name + "\n"
        f.write(newline)

        i += 1
