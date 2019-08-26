# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """

        if not root:
            return root
        l = root.left
        r = root.right
        root.left = self.invertTree(r)
        root.right = self.invertTree(l)

        return root