# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """

        def is_leaf(node):
            return not (node.left or node.right) if node else False

        s = 0
        def traversal(root):
            nonlocal s
            if not root:
                return
            if is_leaf(root.left):
                s+=root.left.val
            traversal(root.left)
            traversal(root.right)

        traversal(root)

        return s

