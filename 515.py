# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def largestValues(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """

        res = []

        def traversal(root, level):
            if not root:
                return
            if level > len(res):
                res.append(root.val)
            elif res[level - 1] < root.val:
                res[level - 1] = root.val
            traversal(root.left, level + 1)
            traversal(root.right, level + 1)
        traversal(root, 1)
        return res
