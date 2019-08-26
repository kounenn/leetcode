# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        if not n:
            return []

        def init_tree(start, end):
            tree_list = []
            if end < start:
                tree_list.append(None)
                return tree_list
            if end == start:
                tree_list.append(TreeNode(start))
                return tree_list
            for i in range(start, end + 1):
                left = init_tree(start, i - 1)
                right = init_tree(i + 1, end)
                for ln in left:
                    for rn in right:
                        root = TreeNode(i)
                        root.left = ln
                        root.right = rn
                        tree_list.append(root)
            return tree_list
        return init_tree(1, n)
