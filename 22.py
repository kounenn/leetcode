class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """

        res = []
        self.addpair(res, "", 0, 0, n)
        return res

    def addpair(self, res, s, ln, rn, n):
        if len(s) == 2 * n:  # 写完
            res.append(s)
            return
        if ln < n:  # 写左括号
            self.addpair(res, s + '(', ln + 1, rn, n)
        if rn < n and rn < ln:  # 写右括号
            self.addpair(res, s + ')', ln, rn + 1, n)
