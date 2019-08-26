# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def findSecondMinimumValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """

        def traversal(root,m):
            if not root:
                return -1
            if root.val != m:
                return root.val
            left = traversal(root.left,m)
            right = traversal(root.right,m)
            if left == -1:
                return right
            if right == -1:
                return left
            return min(left,right)

        return traversal(root,root.val)
        
