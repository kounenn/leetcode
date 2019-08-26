# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findFrequentTreeSum(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        
        res_dict = {}

        def sub_sum(root):
            if not root:
                return 0
            return sub_sum(root.left)+sub_sum(root.right)+root.val

        def traversal(root):
            if not root:
                return
            s = sub_sum(root)
            if s in res_dict:
                res_dict[s]+=1
            else:
                res_dict[s]=1
            traversal(root.left)
            traversal(root.right)
        traversal(root)
        max_s_n = 0
        res_list = []
        for s,n in res_dict.items():
            if n>max_s_n:
                res_list = [s]
                max_s_n = n
            elif n==max_s_n:
                res_list.append(s)
        return res_list
                
        