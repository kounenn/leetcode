# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        def is_same(root1,root2):
            if not (root1 or root2):
                return True
            if root1 and root2 and root1.val==root2.val:
                return is_same(root1.left,root2.right) and is_same(root1.right,root2.left)
            return False

        return is_same(root.left,root.right)