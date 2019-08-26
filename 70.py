class Solution:
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 1:
            return 1 
        res = [0,1,2]
        for i in range(3,n+1):
            res.append(res[i-1]+res[i-2])
        return res[n]