class Solution:
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n<1:
            return ''
        rs = '1'
        for i in range(n-1):
            rs = self.f(rs) 
        return rs
        
    def f(self,string):
        rs = []
        size = len(string)
        ss = string[0]
        n = 1
        for s in string[1:]:
            if s == ss:
                n+=1
            else:
                rs.extend((str(n),ss))
                ss = s
                n = 1
        rs.extend((str(n),ss))
        return ''.join(rs)