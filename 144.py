# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """

        current = root
        stack = []
        res = []
        while current:
            stack.append(current)
            res.append(current.val)
            current = current.left
            while not current and stack:
                current = stack.pop().right
        return res
