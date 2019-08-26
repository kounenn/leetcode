# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """

        size = len(postorder)
        if size == 0:
            return None
        root = TreeNode(postorder[size - 1])
        for i in range(size):
            if postorder[size - 1] == inorder[i]:
                break
        root.left = self.buildTree(inorder[:i], postorder[:i])
        root.right = self.buildTree(inorder[i + 1:], postorder[i:size - 1])
        return root
