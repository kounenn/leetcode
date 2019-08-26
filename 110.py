# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """

        def high(root):
            if not root:
                return 0
            return max(high(root.left), high(root.right)) + 1

        def traversal(root):
            if not root:
                return True
            if abs(high(root.left) - high(root.right)) > 1:
                return False
            return traversal(root.left) and traversal(root.right)
        return traversal(root)
