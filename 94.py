# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """

        current = root
        stack = []
        res = []
        while current:
            stack.append(current)
            current = current.left
            while not current and stack:
                current = stack.pop()
                res.append(current.val)
                current = current.right
        return res
