#!/usr/bin/env python3

"""
1- Write a Python function insert(root, key) that will insert a new node 
with the given key into a binary search tree rooted at root.
The function should maintain the properties of a BST

() is None

             12
            /  \
          11    25
         / \    / \  
        8  ()  ()  30
       / \         / \
      () ()       () ()

"""

class TreeNode(object):
    def __init__(self, data):
        self.data = data
        self.l = None
        self.r = None

def insert(root, key):
    if root is None:
        return TreeNode(key)

    if key > root.data:
        root.r = insert(root.r, key)
    else:
        root.l = insert(root.l, key)

    return root

def InorderPrint(root):
    if root is None:
        return

    InorderPrint(root.l)
    print(root.data)
    InorderPrint(root.r)
 
root = insert(None, 12)
root = insert(root, 11)
root = insert(root, 25)
root = insert(root, 8)
root = insert(root, 30)
#tests:
assert root.data == 12
assert root.l.data == 11
assert root.l.l.data == 8
assert root.l.r == None
assert root.r.data == 25
assert root.r.l == None
assert root.r.r.data == 30
assert root.r.r.l == None
assert root.r.r.r == None
InorderPrint(root)
print("-------------------------------------------------")

"""
2- Implement a Python function is_valid_bst(root) 
that takes a tree and determines if it is a valid binary
search tree.
"""
def is_sorted(a):
    for i in range(len(a) - 1):
        if a[i] > a[i + 1]:
            return False
    return True

def is_valid_bst(root, a = []):
    if root is None:
        return

    is_valid_bst(root.l, a)
    a.append(root.data)
    is_valid_bst(root.r, a)

    return is_sorted(a)
    
print(is_valid_bst(root))
print("-------------------------------------------------")

"""
3- Write a Python function find_kth_smallest(root, k) 
that will return the k-th smallest element in a BST.

k - 1 supposing that k is from 1 to N where N is the len of a
"""

def find_kth_smallest(root, k, a = []):
    if root is None:
        return

    find_kth_smallest(root.l, k, a)
    a.append(root.data)
    find_kth_smallest(root.r, k, a)

    return a[k - 1] 

print(find_kth_smallest(root, 1))
print(find_kth_smallest(root, 2))
print(find_kth_smallest(root, 3))
print(find_kth_smallest(root, 4))
print(find_kth_smallest(root, 5))
print("-------------------------------------------------")

"""
4- A tree is considered height-balanced if for each node, 
the height difference between its left and right subtree is 
at most 1.
Write a function is_balanced(root) that determines 
if a tree is height-balanced.

Height is the number of edeges from the current node to a leaf
taking the longest way.
"""

def height(node):
    if node is None or (node.l == None and node.r == None):
        return 0
    else:
        return 1 + max(height(node.l), height(node.r))

print(height(root))

def is_balanced(root):
    if root is None:
        return True

    if abs(height(root.l) - height(root.r)) > 1:
        return False

    bool_left = is_balanced(root.l)
    bool_right = is_balanced(root.r)

    if bool_left and bool_right:
        return True
    else:
        return False

print(is_balanced(root))
insert(root, 33)
insert(root, 34)
print(is_balanced(root))
print("-------------------------------------------------")

"""
5- Implement an iterative in-order traversal in a BST and
return the values in a list.
"""

def iter_inorder(root, a=[]):
    curr = root

    stack = []

    while True:
        if curr != None:
            stack.append(curr)
            curr = curr.l
        elif stack:
            curr = stack.pop()
            a.append(curr.data)
            curr = curr.r
        else:
            break

    return a

print(iter_inorder(root))
print("-------------------------------------------------")

"""
6- Write a function that finds all the paths from the
root node to the leaf nodes of a binary tree and 
returns them as a list of strings.
"""
def binary_tree_paths(root):
    output = []
    def paths(root, string=""):
        if root == None:
            return

        if root.l == None and root.r == None:
            output.append(string + str(root.data))  

        paths(root.l, string + str(root.data) + "->")
        paths(root.r, string + str(root.data) + "->")

    paths(root)
    return output
#Example usage:
root = TreeNode(1)
root.l = TreeNode(2)
root.r = TreeNode(3)
root.l.r = TreeNode(5)
print(binary_tree_paths(root))
print("-------------------------------------------------")























