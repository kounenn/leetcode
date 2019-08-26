# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """

        s = 0

        def find_sum(root, d):
            nonlocal s
            if not root:
                return
            d -= root.val
            if 0 == d:
                s += 1
            find_sum(root.left, d)
            find_sum(root.right, d)
        
        def traversal(root):
            if not root:
                return
            find_sum(root,sum)
            traversal(root.left)
            traversal(root.right)
            
        traversal(root)

        return s
