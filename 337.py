# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def rob(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """

        def sub_rob(root):
            if not root:
                return 0, 0
            left = sub_rob(root.left)
            right = sub_rob(root.right)
            return max(left[0], left[1]) + max(right[0], right[1]), root.val + left[0] + right[0]
        return max(*sub_rob(root))
