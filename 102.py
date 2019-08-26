# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """

        level_list = []

        def level_traversal(root, level):
            if not root:
                return
            if len(level_list) < level:
                level_list.append([root.val])
            else:
                level_list[level - 1].append(root.val)
            level_traversal(root.left, level + 1)
            level_traversal(root.right, level + 1)
        level_traversal(root, 1)
        return level_list
