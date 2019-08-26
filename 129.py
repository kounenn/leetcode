# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        s = 0

        def traversal(root, n):
            nonlocal s
            if not root:
                return
            if not(root.left or root.right):
                s += 10 * n + root.val
                return
            traversal(root.left, 10 * n + root.val)
            traversal(root.right, 10 * n + root.val)
        traversal(root, 0)
        return s
