from multiprocessing import *
import time

'''
if a parent process creates a child process in variable p1 and then 
calls p1.join(), then the parent process will block on
that join call until p1 completes.
'''

def slowpoke(lock):
    time.sleep(10)
    lock.acquire()
    print("Child process: Ok, I'm coming")
    lock.release()


def haveToWait():
    lock = Lock()
    
    p1 = Process(target=slowpoke, args=(lock,))
    p1.start()

    print("Parent process: waiting...")

    p1.join()
    print("Parent process: finally ez.")

haveToWait()
    
