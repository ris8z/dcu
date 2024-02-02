from multiprocessing import *
from random import randint
import time

'''
Here, the task is to add up a large number of random numbers.
This is accomplished by creating two child processes,
each of which is responsible for half of the work.
'''

def addManyNumbers(numNumbers, q):
    s = 0
    for i in range(numNumbers):
        s = s + randint(1, 100)
    q.put(s)


def addManyPar():
    totnumber = 1000000

    q = Queue()
    p1 = Process(target=addManyNumbers, args=(totnumber//2, q))
    p2 = Process(target=addManyNumbers, args=(totnumber//2, q))
    p1.start()
    p2.start()

    answerA = q.get()
    answerB = q.get()

    print("Sum:", answerA + answerB)

addManyPar()

'''
Here’s an interesting question to consider: 
which child’s result will be in answerA and which in answerB?
The answer is that this is indeterminate.
Whichever child process finishes first will have its answer in answerA,
and the other will be in answerB.
This is not a problem for commutative merging operations,
like the addition of this example, but of course could be a complication for non-commutative merging.
'''
