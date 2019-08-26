# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def findTilt(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """

        tilt = 0
        if not root:
            return tilt

        def traversal(root):
            nonlocal tilt
            if not root:
                return 0
            left = traversal(root.left)
            right = traversal(root.right)
            tilt += abs(left - right)
            return root.val + left + right
        traversal(root)
        return tilt
