# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """

        paths = []
        def traversal(root,path):
            if not root:
                return
            path.append(str(root.val))
            if not (root.left or root.right):
                paths.append('->'.join(path[:]))
            traversal(root.left,path)
            traversal(root.right,path)
            path.pop()
        traversal(root,[])

        return paths
