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
        if not root:
            return root
        p = root
        n = None
        while p.left:
            n = p
            while n:
                n.left.next = n.right
                if n.next:
                    n.right.next = n.next.left
                n = n.next
            p = p.left
