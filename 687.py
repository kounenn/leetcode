# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    length = 0
    def longestUnivaluePath(self, root):
        # 每个结点的左或右箭头长度等于0或它的子结点的最长箭头长度+1（当且仅当结点的值与其左或右结点相等时）
        # 思路：计算每个结点的左右箭头长和以它为连接点的路径长（等于左右箭头长之和），并跟之前最长的路径长进行对比
        """
        :type root: TreeNode
        :rtype: int
        """
        self.arrow_length(root)
        return self.length
    
    def arrow_length(self,root):
        if not root:
            return 0
        left_length = self.arrow_length(root.left)
        right_length = self.arrow_length(root.right)
        left_arrow = right_arrow = 0
        if root.left and root.val==root.left.val:
            left_arrow = left_length+1
        if root.right and root.val==root.right.val:
            right_arrow = right_length+1 
        
        self.length = max(self.length,left_arrow+right_arrow)
        return max(left_arrow,right_arrow)