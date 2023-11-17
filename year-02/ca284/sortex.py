#!/usr/bin/env python3

#its for sorting files after you download it from einstein

import os
import fnmatch
import shutil

def list_files(directory, pattern = "*"):
    file_list = []
    for root, dirs, files in os.walk(directory):
        for filename in fnmatch.filter(files, pattern):
            file_list.append(os.path.join(root, filename))
    return file_list
def move_file(source_path, dest_folder):
    dest_path = os.path.join(dest_folder, os.path.basename(source_path))

    if os.path.exists(dest_path):
        os.remove(dest_path)

    shutil.copy2(source_path, dest_path)

files = list_files(".","*.c")
for filepath in files:
    tokens = filepath.split("/")
    name = tokens[-1]
    tokens = name.split("-")
    dirname = tokens[0]

    if dirname[-1] != "0":
        dirname = dirname[:-1] + "0" + dirname[-1]

    os.makedirs("./" + dirname, exist_ok = True)
    move_file(filepath, "./" + dirname)


