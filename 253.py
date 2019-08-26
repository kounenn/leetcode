# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        def find_node(root, v):
            if not root:
                return False
            if root.val == v:
                return True
            return find_node(root.left, v) or find_node(root.right, v)

        ancestors = []

        def find_ancestor(root, p, q):
            if not root:
                return
            if find_node(root, p.val) and find_node(root, q.val):
                ancestors.append(root)
                find_ancestor(root.left, p, q)
                find_ancestor(root.right, p, q)
            else:
                return
        find_ancestor(root, p, q)
        return ancestors.pop()
