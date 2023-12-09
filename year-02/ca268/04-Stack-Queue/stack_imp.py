class Stack:
    """
    Python implementation the stack
    """

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


## Sample inputs
if __name__ == '__main__':
    s = Stack()

    s.push('A')
    s.push('B')
    s.push('C')
    s.push('D')
    s.push('E')
