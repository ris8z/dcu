#!/usr/bin/env python3

"""
1- Write a Python function insert(root, key) that will insert a new node with the given key into a binary
search tree rooted at root. The function should maintain the properties of a BST.
"""
class TreeNode(object):
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


def insert(root, key):
    if root is None:
        return TreeNode(key)
    
    if key > root.val:
        root.right = insert(root.right, key)
    else:
        root.left = insert(root.left, key)

    return root

# Usage
root = TreeNode(10)
root = insert(root, 5)
root = insert(root, 15)
print(root.val) #should be 10
print(root.left.val) #should be 5
print(root.right.val) #should be 15
