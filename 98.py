# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """

        def max_left(root, n):
            if not root:
                return n
            if root.val > n:
                n = root.val
            return max(max_left(root.left, n), max_left(root.right, n))

        def min_right(root, n):
            if not root:
                return n
            if root.val < n:
                n = root.val
            return min(min_right(root.left, n), min_right(root.left, n))

        def is_bst(root):
            if not root:
                return True
            if root.left and root.val <= max_left(root.left, root.left.val):
                return False
            if root.right and root.val >= min_right(root.right, root.right.val):
                return False
            return is_bst(root.left) and is_bst(root.right)

        return is_bst(root)
