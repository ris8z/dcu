# Q1
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


head = Node(0)
current = head
for i in range(1, 51):
    current.next = Node(2 * i)
    current = current.next

current = head
while current != None:
    print(current.data)
    current = current.next


# Q2
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

    def find(self, data):
        current = self
        while (current != None):
            if current.data == data:
                return current
            current = current.next

        return None


head = Node("Dublin")
another_node = Node("Galway")
head.next = another_node
a_third_node = Node("Cork")
another_node.next = a_third_node

print("Found: " + str(head.find("Galway").data))


# Q3
def reverse_rec(node):
    if node is None or node.next is None:
        return node

    rest = reverse_rec(node.next)

    node.next.next = node
    node.next = None

    return rest


reversed_node = reverse_rec(head)


# Q4
class SwapNodesInPairs:
    def swap_pairs(self, head):
        # Dummy node
        dummy = Node(0)
        # Point the next of dummy node to the head
        dummy.next = head
        # This node will be used to traverse the list
        current = dummy
        # Loop until we reach to the second last node
        while current.next is not None and current.next.next is not None:
            # First node of the pair
            first = current.next
            # Second node of the pair
            second = current.next.next
            # Point the next of first node to the node after second node
            first.next = second.next
            # Now the current node's next should be the second node
            current.next = second
            # Linking the original second node to the first node
            current.next.next = first
            # Move the pointer two nodes ahead
            current = current.next.next
        return dummy.next

    def print_list(self, head):
        temp = head
        while temp is not None:
            print(temp.data, end=" ")
            temp = temp.next
        print()


s = SwapNodesInPairs()
head = Node(1)
head.next = Node(2)
head.next.next = Node(3)
head.next.next.next = Node(4)
s.print_list(head)
s.print_list(s.swap_pairs(head))


# Q5
def remove_nth_from_end(head, n):
    fast = slow = head
    for _ in range(n):
        fast = fast.next
    if not fast:
        return head.next
    while fast.next:
        fast = fast.next
        slow = slow.next
    slow.next = slow.next.next
    return head


head = Node(1)
head.next = Node(2)
head.next.next = Node(3)
head.next.next.next = Node(4)
head.next.next.next.next = Node(5)

output = remove_nth_from_end(head, 3)
