# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        if not root:
            return False
        d = sum - root.val
        if (not (root.left or root.right)) and d == 0:
            return True

        return self.hasPathSum(root.left, d) or self.hasPathSum(root.right, d)
