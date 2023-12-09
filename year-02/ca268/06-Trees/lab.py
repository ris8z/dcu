#!/usr/bin/env python3

"""
Write a Python function insert(root, key)
that will insert a new node with the given key into a binary search tree rooted at root. 
The function should maintain the properties of a BST.
"""
class TreeNode:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

def insert(root, key):
    if root is None:
        return TreeNode(key)

    if key > root.val:
        root.right = insert(root.right, key)
    else:
        root.left = insert(root.left, key)

    return root

def in_order(root):
    if root:
        in_order(root.left)
        print(root.val)
        in_order(root.right)

def printTree(node, level=0):
    if node != None:
        printTree(node.left, level + 1)
        print(' ' * 4 * level + '-> ' + str(node.val))
        printTree(node.right, level + 1)

root = None
root = insert(root, 2)
root = insert(root, 1)
root = insert(root, 5)

assert(root.val == 2)
assert(root.left.val == 1)
assert(root.right.val == 5)
#in_order(root)
#printTree(root)

"""
Implement a Python function is_valid_bst(root) that takes a tree and determines 
if it is a valid binary search tree.
"""

def is_valid_bst(root, Min = float("-inf"), Max = float("inf")):
    if root == None:
        return True
    
    if not (Min <= root.val and root.val <= Max):
        return False
    
    Bool_left = is_valid_bst(root.left, Min, root.val)
    Bool_right = is_valid_bst(root.right, root.val, Max)

    if Bool_left and Bool_right:
        return True
    else:
        return False

root = None 
# Usage
root = TreeNode(2)
root.left = TreeNode(1)
root.right = TreeNode(3)

assert(is_valid_bst(root) == True)

"""
Write a Python function find_kth_smallest(root, k) that will return the k-th smallest
element in a BST.
"""

def get_sorted_list(root):
    lst = []
    def add_element(root):
        if root:
            add_element(root.left)
            lst.append(root.val)
            add_element(root.right)
    add_element(root)
    return lst

def find_kth_smallest(root, k):
    #let be the value of k: 1 to N
    return get_sorted_list(root)[k - 1]

root = None
root = insert(root, 10)
root = insert(root, 1)
root = insert(root, 0)
root = insert(root, 15)

assert(find_kth_smallest(root, 2) == 1)

"""
A tree is considered height-balanced if for each node, the height difference
between its left and right subtree is at most 1. Write a function is_balanced(root)
that determines if a tree is height-balanced.
"""
def height(node):
    if node == None:
        return 0
    return 1 + max(height(node.left), height(node.right))

def is_balanced(root):
    if root == None:
        return True

    if abs(height(root.left) - height(root.right)) > 1:
        return False

    bool_left = is_balanced(root.left)
    bool_right = is_balanced(root.right)

    if bool_left and bool_right:
        return True
    else:
        return False

root = None
a = root = TreeNode(1)
b = root.left = TreeNode(4)
c = root.right = TreeNode(2)
d = root.right.right = TreeNode(3)

assert(height(a) == 3)
assert(height(b) == 1)
assert(height(c) == 2)
assert(height(d) == 1)

assert(is_balanced(root) == True)
d.right = TreeNode(6)
assert(is_balanced(root) == False)

"""
Implement an iterative in-order traversal in a BST and return the values in a list.
"""

def iter_in_order(root):
    stack = []
    curr = root
    result = []

    while True:
        if curr:
            stack.append(curr)
            curr = curr.left
        elif curr == None and stack:
            tmp = stack.pop()
            result.append(tmp.val)
            curr = tmp.right
        else:
            break
    return result
    
root = None
root = insert(root, 3)
root = insert(root, 1)
root = insert(root, 0)
root = insert(root, 2)
root = insert(root, 4)

assert(iter_in_order(root) == [0, 1, 2, 3, 4])
root = insert(root, -1)
root = insert(root, 5)
assert(iter_in_order(root) == [-1, 0, 1, 2, 3, 4, 5])

# Usage
root = None
root = TreeNode(1)
root.right = TreeNode(2)
root.right.left = TreeNode(3)
assert(iter_in_order(root) == [1, 3, 2]) # Should print [1, 3, 2]

"""
Write a function that finds all the paths from the root node to the leaf nodes 
of a binary tree and returns them as a list of strings
"""
def bin_tree_paths(root):
    lst = []
    def all_paths(root, string=""):
        if root == None:
            return

        if root.left == None and root.right == None:
            string += str(root.val)
            lst.append(string)
            return

        string += str(root.val) + "->"
        all_paths(root.left, string)
        all_paths(root.right, string)
    all_paths(root)
    return lst

# Example usage:
root = None
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.right = TreeNode(5)

assert(bin_tree_paths(root) == ["1->2->5", "1->3"])
root.left.left = TreeNode(4)
assert(bin_tree_paths(root) == ["1->2->4", "1->2->5", "1->3"])
