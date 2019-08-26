# Definition for binary tree with next pointer.
# class TreeLinkNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None


class Solution:
    # @param root, a tree link node
    # @return nothing
    def connect(self, root):
        p = root
        c = dummy = TreeNode(0)
        while p:
            c.next = p.left
            if c.next:
                c = c.next
            c.next = p.right
            if c.next:
                c = c.next

            p = p.next

            if not p:
                c = dummy
                p = dummy.next
