# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """

        def high(root):
            if not root:
                return -1
            return max(high(root.left), high(root.right)) + 1

        def diameter(root):
            if not root:
                return 0
            return 2 + high(root.left) + high(root.right)

        def max_diameter(root):
            if not root:
                return 0
            return max(diameter(root), max_diameter(root.left), max_diameter(root.right))

        return max_diameter(root)
