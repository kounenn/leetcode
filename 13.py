class Solution:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        def check(res, m):
            return m*(1 if res < 5*m else -1)
        res = 0
        for n in reversed(s):
            if 'I' == n:
                res += check(res, 1)
            elif 'V' == n:
                res += 5
            elif 'X' == n:
                res += check(res, 10)
            elif 'L' == n:
                res += 50
            elif 'C' == n:
                res += check(res, 100)
            elif 'D' == n:
                res += 500
            elif 'M' == n:
                res += 1000
        return res
