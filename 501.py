# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def findMode(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """

        def find_mode_num(root, val):
            s = 0
            if not root:
                return s
            if root.val == val:
                s += 1
            s += find_mode_num(root.left, val)
            s += find_mode_num(root.right, val)
            return s

        m = 0
        n = []

        def traversal(root):
            nonlocal m
            nonlocal n
            if not root:
                return
            if not root.val in n:
                num = find_mode_num(root, root.val)
                if num > m:
                    m = num
                    n = [root.val]
                elif num == m:
                    n.append(root.val)
            traversal(root.left)
            traversal(root.right)

        traversal(root)
        return n
