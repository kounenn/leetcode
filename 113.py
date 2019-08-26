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
        :rtype: List[List[int]]
        """

        paths = []
        
        def travelsal(root,d,path):
            if not root:
                return
            path.append(root.val)
            d -=root.val
            if d == 0 and (not root.left and not root.right):
                paths.append(path[:])
            travelsal(root.left,d,path)
            travelsal(root.right,d,path)
            path.pop()
        
        travelsal(root,sum,[])

        return paths