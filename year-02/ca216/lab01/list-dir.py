import os
import sys



if len(sys.argv) == 2:
    path = sys.argv[1]
else:
    path = "."


files = os.listdir(path)

for name in files:
    print(name)
    full_path = os.path.join(path, name)
    print(full_path)

    inode = os.stat(full_path)

    print(' ' + str(inode.st_size))
    print(' ' + str(inode.st_mode))
    print(' ' + ("f" if inode.st_mode & 0o0100000 else '-'))
    print(' ' + ("d" if inode.st_mode & 0o0040000 else '-'))

    #or we could have used this

    if os.path.isdir(full_path):
        print(' dir')
    elif os.path.isfile(full_path):
        print(' file')
        print(' ' + str(os.path.getsize(full_path)))
    else:
        print('Not a file or a dir - what else could be?')



    print("----------------------------")
