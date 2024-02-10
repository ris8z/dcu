from multiprocessing import *

'''
Here we make three different Process objects. It is important to note that each process uses the same sayHi
function defined before, but each process executes that function independent of the
others. Each child process will print its own unique pid.
'''
def sayHi(name): 
    print("hi", name, " from process", current_process().pid)

def manyGreetings():
    print("hi from process", current_process().pid, "main process")

    name = "Giuseppe"

    p1 = Process(target=sayHi, args=(name,))
    p2 = Process(target=sayHi, args=(name,))
    p3 = Process(target=sayHi, args=(name,))

    p1.start()
    p2.start()
    p3.start()

manyGreetings()
