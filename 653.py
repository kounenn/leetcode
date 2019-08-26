class Solution:
    def findTarget(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: bool
        """
        
        nl = []
        def traversal(root):
            if not root:
                return
            traversal(root.left)
            nl.append(root.val)
            traversal(root.right)
        
        traversal(root)
        i = 0
        j = len(nl)-1
        while i<j:
            s = nl[i]+nl[j]
            if s == k:
                return True
            if s<k:
                i+=1
            else:
                j-=1
        return False