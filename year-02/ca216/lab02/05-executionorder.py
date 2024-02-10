from multiprocessing import *

def sayHi3(personName):
    print("Hi", personName, "from process", current_process().name, "- pid", current_process().pid)

def manyGreetings3():
    print("Hi from process", current_process().pid, "(parent process)")
    personName = "Jimmy"
    for i in range(10):
        Process(target=sayHi3, args=(personName,), name=str(i)).start()

manyGreetings3()


"""
Hi from process 3988 (main process)
Hi HJHimmyiHii   Jimmy  from process 0 -JfJ pid 5164
immyrom process 4 - pid 4332
immy from process  from process 7 - pid8  5236- pid
 3564
 Hi Jimmy from process 1 - pidH 6884
 i Jimmy from process 5 - pid 3652
 Hi Jimmy from process 5 - pid 1060
 Hi Jimmy from process 2 - pid 176
 Hi Jimmy from process 3 - pid 5812
 Hi Jimmy from process 9 - pid 4732
"""
