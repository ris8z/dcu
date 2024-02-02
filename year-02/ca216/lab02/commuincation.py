import time
from multiprocessing import *
from random import randint

def great(q):
    #print("(child process) Wating for a name...")
    #name = q.get()
    #print("(child process) Well, hi", name)

    for _ in range(5):
        print("\n\n(child process) Wating for a name...")
        name = q.get()
        print("(child process) Well, hi", name)



def sendName():
    q = Queue()

    p1 = Process(target=great, args=(q,))
    p1.start()



    names = ["Giuseppe", "Sabrina", "Peppe", "Matteo", "Waleed"]

    #time.sleep(5) # wait 5 second
    #print("(parent process) Ok, I'll send the name")
    #q.put("Jimmy")

    for name in names:
        time.sleep(randint(1,4))
        print("(parent process) Ok, I'll send", name)
        q.put(name)




sendName()
