class Solution:
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        covmap = [
            ['I', 'V'],
            ['X', 'L'],
            ['C', 'D'],
            ['M', '']
        ]

        def cov(num, n):
            if num == 4:
                return covmap[n][0]+covmap[n][1]
            if num == 9:
                return covmap[n][0]+covmap[n+1][0]
            else:
                if num >= 5:
                    return covmap[n][1]+(num-5)*covmap[n][0]
                return num*covmap[n][0]
        res = ''
        i = 0
        while num:
            num, n = divmod(num, 10)
            res = cov(n, i)+res
            i += 1
        return res
