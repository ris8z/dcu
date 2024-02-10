'''
Let’s try another exercise now.
Write a function that first asks for your name, and then asks how many processes to spawn.
That many processes are created, 
and each greets you by name and gives its pid. Try this on your own before moving on.
Hint: use a loop to create the number of desired child processes.
'''
from multiprocessing import *

def sayHi(name):
    print("Hi", name, "from process:", current_process().pid)

def main():
    print("Name ? : ")
    name = input()
    print("how many process to spawn? : ")
    n_process = int(input())

    for _ in range(n_process):
        p = Process(target=sayHi, args=(name,))
        p.start()

main()
