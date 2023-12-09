# Q1
class TreeNode:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key


def insert(root, key):
    if root is None:
        return TreeNode(key)
    else:
        if root.val < key:
            root.right = insert(root.right, key)
        else:
            root.left = insert(root.left, key)
    return root


# Usage
# root = TreeNode(10)
# root = insert(root, 5)
# root = insert(root, 15)


# Q2
# Assume TreeNode class definition is the same as Q1

def is_valid_bst(root, min_val=float('-inf'), max_val=float('inf')):
    if root is None:
        return True
    if not min_val < root.val < max_val:
        return False
    return (is_valid_bst(root.left, min_val, root.val) and
            is_valid_bst(root.right, root.val, max_val))


# Usage
# root = TreeNode(2)
# root.left = TreeNode(1)
# root.right = TreeNode(3)
# print(is_valid_bst(root)) # Should return True


# Q3
# Assume TreeNode class definition is the same as Q1

def inorder_traversal(root):
    return inorder_traversal(root.left) + [root.val] + inorder_traversal(root.right) if root else []


def find_kth_smallest(root, k):
    return inorder_traversal(root)[k - 1]


# Usage
# root = ...
# k = 2
# print(find_kth_smallest(root, k))


# Q4
# Assume TreeNode class definition is the same as Q1

def is_balanced(root):
    def check_balance(node):
        if node is None:
            return 0, True

        left_height, left_balanced = check_balance(node.left)
        right_height, right_balanced = check_balance(node.right)

        balanced = (left_balanced and right_balanced and
                    abs(left_height - right_height) <= 1)

        return max(left_height, right_height) + 1, balanced

    _, is_bal = check_balance(root)
    return is_bal


# Usage
# root = ...
# print(is_balanced(root)) # Should return True or False


# Q5
# Assume TreeNode class definition is the same as Q1

def iterative_in_order_traversal(root):
    stack = []
    current = root
    in_order_values = []

    while current is not None or stack:
        # Reach the leftmost Node of the current Node
        while current is not None:
            # Place pointer to a tree node on the stack
            # before traversing the node's left subtree
            stack.append(current)
            current = current.left

        # BackTrack from the empty subtree and visit the Node
        # at the top of the stack
        current = stack.pop()
        in_order_values.append(current.val)  # Add the node's value

        # We have visited the node and its left subtree.
        # Now, it's right subtree's turn
        current = current.right

    return in_order_values


# Usage
#  root = TreeNode(1)
# root.right = TreeNode(2)
# root.right.left = TreeNode(3)
# print(iterative_in_order_traversal(root)) # Should print [1, 3, 2]


# Q6
# Assume TreeNode class definition is the same as Q1

def binary_tree_paths(root):
    def construct_paths(node, path):
        if node:
            path += str(node.val)
            if not node.left and not node.right:  # if leaf node
                paths.append(path)  # add path to paths
            else:
                path += '->'  # extend path
                construct_paths(node.left, path)
                construct_paths(node.right, path)

    paths = []
    construct_paths(root, '')
    return paths

# Example usage:
# root = TreeNode(1)
# root.left = TreeNode(2)
# root.right = TreeNode(3)
# root.left.right = TreeNode(5)
# print(binary_tree_paths(root))  # Output: ["1->2->5", "1->3"]
