class Deque:
    """
    Python implementation the deques
    """

    def __init__(self):
        self.items = []

    def is_empty(self):
        return len(self.items) == 0

    def add_first(self, e):
        self.items.insert(0, e)

    def add_last(self, e):
        self.items.append(e)

    def delete_first(self):
        if self.is_empty():
            raise ValueError("Deque is empty")
        return self.items.pop(0)

    def delete_last(self):
        if self.is_empty():
            raise ValueError("Deque is empty")
        return self.items.pop()

    def first(self):
        if self.is_empty():
            raise ValueError("Deque is empty")
        return self.items[0]

    def last(self):
        if self.is_empty():
            raise ValueError("Deque is empty")
        return self.items[-1]

    def __len__(self):
        return len(self.items)


if __name__ == '__main__':
    d = Deque()
    d.add_first(1)
    d.add_last(2)
    d.add_first(3)
    print(d.items)
    print(d.delete_first())
    print(len(d))
    print(d.delete_last())
    print(d.first())
    print(d.last())
    print(d.is_empty())
    print(len(d))
    d.delete_last()
    print(d.is_empty())
    print(len(d))
