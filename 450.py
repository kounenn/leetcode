# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def deleteNode(self, root, key):
        """
        :type root: TreeNode
        :type key: int
        :rtype: TreeNode
        """

        def find_left(root):
            if not root.left:
                return root
            return find_left(root.left)

        def is_leaf(root):
            return not (root.left or root.right)

        if not root:
            return root
        if root.val == key:
            if is_leaf(root):
                root = None
            elif not root.left:
                root = root.right
            elif not root.right:
                root = root.left
            else:
                node = find_left(root.right)
                node.left = root.left
                root = root.right
            return root
        root.left = self.deleteNode(root.left,key)
        root.right = self.deleteNode(root.right,key)

        return root
