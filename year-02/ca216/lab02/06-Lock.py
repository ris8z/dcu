from multiprocessing import *

def sayHi3(lock, personName):
    lock.acquire()
    print("Hi", personName, "from process", current_process().name, "- pid", current_process().pid)
    lock.release()

def manyGreetings3():
    print("Hi from process", current_process().pid, "(parent process)")
    
    personName = "Peppe"
    lock1 = Lock()

    for i in range(10):
        Process(target=sayHi3, args=(lock1, personName), name=str(i)).start()

manyGreetings3()


"""
As in the previous example, the order of execution of the processes is still arbitrary.
That is, the acquisition of the lock is arbitrary, and so subsequent runs of the code are likely 
to produce different orderings. It is not necessarily the process that was created first,
or that has been waiting the longest, that gets to acquire the lock next.


almeno non hai output sputtanato che due processi scrivono contemproanemante sullo stardarnd output
pk solo uno alla volta puoi scriverelo grazie al lock
"""
