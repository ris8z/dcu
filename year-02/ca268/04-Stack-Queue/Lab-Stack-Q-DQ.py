# Q1
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
        if (self.is_empty()):
            return
        temp = self.items[-1]
        self.dequeue()
        self.reverse()
        self.enqueue(temp)

    def reverse_k_element(self, k):
        tmp = Queue()
        to_be_reversed = self.items[0:k]
        tmp.items = to_be_reversed
        tmp.reverse()
        tmp.items.extend(self.items[k:])
        for _ in range(self.size()):
            self.dequeue()
            self.enqueue(tmp.dequeue())

    def push_to_last(self, q_size):
        # pop the front element and push
        if q_size <= 0:
            return

        self.items.append(self.items.pop(0))
        self.push_to_last(q_size - 1)

    def enqueue_conditioned(self, temp, q_size):
        if self.is_empty() or q_size == 0:
            self.items.append(temp)
            return

        elif temp <= self.items[0]:
            self.items.append(temp)
            self.push_to_last(q_size)

        else:
            self.items.append(self.items.pop(0))
            self.enqueue_conditioned(temp, q_size - 1)

    def sort_queue(self):
        if self.is_empty():
            return

        temp = self.items.pop(0)
        self.sort_queue()

        self.enqueue_conditioned(temp, self.size())


q = Queue()
q.enqueue(22)
q.enqueue(10)
q.enqueue(65)
q.enqueue(50)
q.enqueue(5)
q.enqueue(18)

# Reversing a Queue
'''print(q.items)
q.reverse()
print(q.items)'''

# Sort the Queue using Recursion
print(q.items)
q.sort_queue()
print(q.items)

# Reversing First K Elements of the Queue
print(q.items)
q.reverse_k_element(5)
print(q.items)


# Q2
def generate_binary_numbers(n):
    # Initialize a queue with the binary number '1'
    q = Queue()
    q.enqueue('1')

    # List to store the binary numbers
    result = []

    # Generate n binary numbers
    for _ in range(n):
        # Dequeue the front binary number and print it
        curr = q.dequeue()
        result.append(curr)

        # Enqueue the next two binary numbers
        q.enqueue(curr + '0')
        q.enqueue(curr + '1')

    return result


n = 16
binary_sequence = generate_binary_numbers(n)
print(' '.join(binary_sequence))


# Q3
class Stack:
    '''Python implementation the stack'''

    def __init__(self):
        self.items = []

    def is_empty(self):
        return self.items == []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def top(self):
        return self.items[len(self.items) - 1]

    def size(self):
        return len(self.items)


s = Stack()
output = []
str_input = 'EAS*Y*QUE***ST***IO*N***'
for i in str_input:
    if i not in '*':
        s.push(i)
    else:
        output.append(s.pop())

print('\n' + str(output))


# Q4
q = Queue()
output = []
str_input = 'EAS*Y*QUE***ST***IO*N***'
for i in str_input:
    if i not in '*':
        q.enqueue(i)
    else:
        output.append(q.dequeue())

print('\n' + str(output))


# Q5
def reverse(string_input):
    n = len(string_input)
    stack = Stack()

    for i in range(0, n, 1):
        stack.push(string_input[i])
    string_output = ""

    for i in range(0, n, 1):
        string_output += stack.pop()

    return string_output


str_input = "Hello DCU!"
str_output = reverse(str_input)
print("\nReversed string is: " + str_output)


# Q6: this is a solution for single digit formula
def evaluate_postfix(formula):
    OPERATORS = set(['+', '-', '*', '/', '(', ')', '^'])
    stack = Stack()
    for ch in formula:
        if ch not in OPERATORS:
            stack.push(float(ch))
        else:
            b = stack.pop()
            a = stack.pop()
            c = {'+': a + b, '-': a - b, '*': a * b, '/': a / b, '^': a ** b}[ch]
            stack.push(c)
    return stack.pop()


exp = "1432^*+147--+"
obj = evaluate_postfix(exp)
print("\nPostfix evaluation: %d" % obj)
