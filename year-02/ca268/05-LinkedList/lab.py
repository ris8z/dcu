#!/usr/bin/env python3

"""
Write a script that assigns all of the even numbers from 0 to 100 to a linked list, and then prints out all 
of the items in the list. A simple Node class is provided.
"""
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
    def find(self, target):
        curr = self
        while curr and curr.data != target:
            curr = curr.next
        if curr:
            return curr
        else:
            return None


def insert(head, value):
    if head is None:
        return Node(value)
    head.next = insert(head.next, value)
    return head

def display(head):
    if head:
        print(head.data,"-> " , end="")
        display(head.next)
    else:
        print("NULL")

head = None
for i in range(100):
    if i % 2 == 0:
        head = insert(head, i)

#display(head)

"""
Write a method find for the Node class that takes a data item as parameter,
and returns a reference to the first node in the linked list 
containing that item, or None if the item is not found.
"""
head = None
head = insert(head, "Dublin")
head = insert(head, "Galway")
head = insert(head, "Cork")
#display(head)

assert(head.next.next == head.find("Cork"))
assert(head.find("Galway").data == "Galway")

"""
Write a recursive function to take a linked list as input and reverse it
"""

def reverse(head):
    if head is None or head.next is None:
        return head
    
    node = reverse(head.next)
    head.next.next = head
    head.next = None

    return node

head = None
head = insert(head, 1)
head = insert(head, 2)
head = insert(head, 3)

#display(head)
head = reverse(head)
#display(head)

"""
Given a linked list, swap every two adjacent nodes and return its head. 
You may not modify the values in the list’s nodes. 
Only nodes itself may be changed.

head → 1 2 3 4 
swap_pairs(head) → 2 1 4 3
"""

def swap(head):
    dummy = Node(0)
    dummy.next = head

    curr = dummy
    while curr and curr.next and curr.next.next:
        a = curr.next
        b = curr.next.next
        c = curr.next.next.next
        
        curr.next = b
        b.next = a
        a.next = c

        curr = curr.next.next
    
    return dummy.next

head = None
head = insert(head, 1)
head = insert(head, 2)
head = insert(head, 3)
head = insert(head, 4)

#display(head)
head = swap(head)
#display(head)

"""
Write a function to take a linked list and an integer.
The function should remove the nth node 
(indicated by the integer) from the end of the list and return its head.

Input: head = [1, 2, 3, 4, 5], n = 3
Output: [1, 2, 4, 5]
"""

def remove_nth(head, k):
    k = lenght(head) - k
    Dummy = Node(0)
    Dummy.next = head

    curr = Dummy
    while curr and k > 0:
        curr = curr.next
        k -= 1

    curr.next = curr.next.next
    return Dummy.next

def lenght(head):
    if head is None:
        return 0
    return 1 + lenght(head.next)

head = None
head = insert(head, 1)
head = insert(head, 2)
head = insert(head, 3)
head = insert(head, 4)
head = insert(head, 5)

#display(head)
head = remove_nth(head, 3)
#display(head)
