class Queue:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return self.items == []

    def enqueue(self, item):
        self.items.insert(0, item)

    def dequeue(self):
        return self.items.pop()

    def size(self):
        return len(self.items)

    def reverse(self):
        if self.is_empty():
            return
        n = self.dequeue()
        self.reverse()
        self.enqueue(n)
        
    def get_max(self, i, j):
        idx = -1
        value = float('-inf')
        while i <= self.size() - 1:
            if i <= j and self.items[-1] > value:
                value = self.items[-1]
                idx = i
            self.enqueue(self.dequeue())
            i += 1
        return idx

    def remove_at_index(self, target):
        if target >= self.size():
            return None
        i = 0
        while i < self.size():
            if i == target:
                result = self.dequeue()
            self.enqueue(self.dequeue())
            i += 1
        return result

    def selection_sort(self, i = 0):
        if i == self.size():
            return

        idx = self.get_max(0, self.size() - 1 - i)
        val = self.remove_at_index(idx)
        self.enqueue(val)
        
        self.selection_sort(i + 1)

    def reverse_k(self, k):
        #we need to pop self.size() - k element
        popped = []
        for i in range(self.size() - k):
            popped.append(self.dequeue())
        self.reverse()
        for i in range(len(popped)):
            self.items.append(popped[len(popped) - 1 - i])

q = Queue()
q.enqueue(22)
q.enqueue(10)
q.enqueue(65)
q.enqueue(50)
q.enqueue(5)
q.enqueue(18)

"""
Add the following functionalities to the queue implementation.

Reversing a Queue
Sort the Queue using Recursion
Reversing First K Elements of the Queue
"""
print("\nNumber 1 -------")
print("Reverse:")
print("before", q.items)
q.reverse()
print("after", q.items)


print("\nSort:")
print("before", q.items)
q.selection_sort()
print("after", q.items)

k = 5
print("\nReverese k =",k)
print("before", q.items)
q.reverse_k(k)
print("after", q.items)


"""
 Write a function using the queue data structure to generate
 a sequence of binary numbers from 1 to n. 

 Example:

 Given n=16 the binary sequence is: 1 10 11 100 101 110 111 1000 
 1001 1010 1011 1100 1101 1110 1111 10000

"""
def generate_bin(n):
    queue = ["1"]
    result = []
    i = 0
    while i < n:
        tmp = queue.pop()
        result.append(tmp)
        queue.insert(0, tmp + "0")
        queue.insert(0, tmp + "1")
        i += 1
    return result

expected_output = "1 10 11 100 101 110 111 1000 1001 1010 1011 1100 1101 1110 1111 10000".split()
assert(generate_bin(16) == expected_output)

print("\nNumber 2 -------")
k = 5
print("Generate bin 1 to ", k)
print(generate_bin(k))

"""
A letter means push and an asterisk means pop in the following sequence.
Write a script to show the sequence of values returned
by the pop operations when this
sequence of operations is performed on an initially empty LIFO stack.


'EAS*Y*QUE***ST***IO*N***'  ['S', 'Y', 'E', 'U', 'Q', 'T', 'S', 'A', 'O', 'N', 'I', 'E']
"""

def solution3(string):
    stack = []
    popped = []
    for char in string:
        if char == "*":
            popped.append(stack.pop())
        else:
            stack.append(char)
    return popped

exp = ['S', 'Y', 'E', 'U', 'Q', 'T', 'S', 'A', 'O', 'N', 'I', 'E']
assert(solution3("EAS*Y*QUE***ST***IO*N***") == exp)

print("\nNumber 3 -------")
print(solution3("EAS*Y*QUE***ST***IO*N***"))

"""
A letter means put and an asterisk means get in the following sequence.
Write a script to show the sequence of valuesreturned by the
get operation when this sequence of operations is performed 
on an initially empty FIFO queue.
"""

def solution4(string):
    queue = []
    popped = []
    for char in string:
        if char == "*":
            popped.append(queue.pop())
        else:
            queue.insert(0, char)
    return popped

exp = ['E', 'A', 'S', 'Y', 'Q', 'U', 'E', 'S', 'T', 'I', 'O', 'N']
assert(solution4("EAS*Y*QUE***ST***IO*N***") == exp)


print("\nNumber 4 -------")
print(solution4("EAS*Y*QUE***ST***IO*N***"))

"""
 Write a script that reads a sequence of characters and prints 
 them in reverse order.  Use a stack.
"""

def solution5(string):
    stack = []
    for char in string:
        stack.append(char)
    output = ""
    while stack:
        output += stack.pop()
    return output

assert(solution5("12345") == "54321")

print("\nNumber 5 -------")
k = "12345"
print(k, solution5(k))

"""
Create a function to evaluate the following postfix expression 
using Stack data structure.

"1432^*+147--+" -> 41
"""
d = {
    "+": lambda a, b: a + b,
    "-": lambda a, b: a - b,
    "*": lambda a, b: a * b,
    "/": lambda a, b: a / b,
    "^": lambda a, b: a ** b,
}

def postfix(string):
    stack = []
    for char in string:
        if char not in d:
            stack.append(int(char))
        else:
            b = stack.pop()
            a = stack.pop()
            stack.append(d[char](a, b))

    if stack:
        return stack[0]

assert(postfix("1432^*+147--+") == 41)

print("\nNumber 6 -------")
print(postfix("1432^*+147--+"))














