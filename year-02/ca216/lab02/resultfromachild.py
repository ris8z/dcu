from multiprocessing import *
import time

def addTwoNumber(a, b, q):
    time.sleep(5)
    q.put(a + b)


def addTwoPar():
    x = int(input("enter a number: "))
    y = int(input("enter a number: "))

    q = Queue()
    
    p1 = Process(target=addTwoNumber, args=(x, y, q))
    p1.start()

    print("waiting for the result...")
    result = q.get()
    print(result)


addTwoPar()
