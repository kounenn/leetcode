class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        rlist = []
        for i in range(numRows):
            rlist.append([])

        l = len(s)
        if numRows <=1:
            return s
        j,op = 0,1
        for i in range(l):
            if j==numRows-1:
                op=-1
            elif j==0:
                op=1
            rlist[j].append(s[i])
            j += op
       
        return ''.join([i for l in rlist for i in l])