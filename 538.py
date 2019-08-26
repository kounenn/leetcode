# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    s = 0
    def convertBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if not root:
            return root
        root.right = self.convertBST(root.right)
        root.val += self.s
        self.s = root.val
        root.left = self.convertBST(root.left)

        return root

        