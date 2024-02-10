from multiprocessing import *


def report(lock, hole):
    lock.acquire()
    print("Hiddy-ho!  I'm worker", current_process().name, " and today I have to dig hole", hole)
    lock.release()

def assingDiggers():
    
    lock1 = Lock()
    worker = ['A','B','C','D','E','F','G','H','I','J']
    for hole, person_name in enumerate(worker):
        p = Process(target=report, args=(lock1, hole), name=person_name)
        p.start()

assingDiggers()
        
