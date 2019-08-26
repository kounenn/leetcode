# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """

        nodes = []

        def traversal(node):
            if not node:
                return
            nodes.append(node)
            traversal(node.left)
            traversal(node.right)
        traversal(root)
        for i in range(1,len(nodes)):
            nodes[i-1].left = None
            nodes[i-1].right = nodes[i]