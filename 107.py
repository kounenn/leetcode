# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        
        def high(root):
            if not root:
                return 0
            return max(high(root.left),high(root.right))+1
        

        h = high(root)
        lst = [[] for i in range(h)]
        def traversal(root,level):
            if not root:
                return
            lst[level-1].append(root.val)
            traversal(root.left,level-1)
            traversal(root.right,level-1)
        traversal(root,h)
        return lst
