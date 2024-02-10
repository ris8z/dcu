from multiprocessing import *

'''
Here we make three different Process objects. It is important to note that each process uses the same sayHi
function defined before, but each process executes that function independent of the
others. Each child process will print its own unique pid.
'''
def sayHi(): 
    print("hi from process", current_process().pid)

def procEx2():
    print("hi from process", current_process().pid, "parent process")

    p1 = Process(target=sayHi, args=())
    p2 = Process(target=sayHi, args=())
    p3 = Process(target=sayHi, args=())

    p1.start()
    p2.start()
    p3.start()

procEx2()
