# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """

        stack = []
        res = []
        current = root
        while current:
            res = [current.val] + res
            stack.append(current)
            current = current.right
            while not current and stack:
                current = stack.pop().left
        return res
