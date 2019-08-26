class Solution:
    def tree2str(self, t):
        """
        :type t: TreeNode
        :rtype: str
        """
        s = ''
        if not t:
            return s
        s+=str(t.val)
        sl=self.tree2str(t.left)
        sr=self.tree2str(t.right)
        if sl:
            sl = '('+sl+')'
            s+=sl
        if sr:
            sr = '('+sr+')'
            if not sl:
                s+='()'
            s+=sr
        return s
            
            