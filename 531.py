# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findBottomLeftValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        
        res = (0,0)
        def traversal(root,level):
            nonlocal res
            if not root:
                return
            if res[1]<level:
                res = (root.val,level)
            traversal(root.left,level+1)
            traversal(root.right,level+1)
        traversal(root,1)
        return res[0]