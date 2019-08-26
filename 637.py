# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def averageOfLevels(self, root):
        """
        :type root: TreeNode
        :rtype: List[float]
        """
        
        lst = []

        def traversal(root,level):
            if not root:
                return
            if level > len(lst)-1:
                lst.append([root.val,1])
            else:
                lst[level][0]+=root.val
                lst[level][1]+=1
            traversal(root.left,level+1)
            traversal(root.right,level+1)
        
        traversal(root,0)
            
        return [i[0]/i[1] for i in lst]