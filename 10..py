class Solution(object):
    cache = {}
    def isMatch(self, s, p):
        """
            :type s: str
            :type p: str
            :rtype: bool
        """
        """
            末尾为*的情况有2种可能
            1. p[:-2]匹配s(此时*表示p[-2]出现0次)
            2. p[-2]==s[-1]或p[-2]为.,且p匹配s[:-1](此时*表示p[-2]出现1或多次)
        """
        if (s, p) in self.cache:
            return self.cache[(s, p)]
        if not p:
            return not s
        if p[-1] == '*':
            if self.isMatch(s, p[:-2]):
                self.cache[(s, p)] = True
                return True
            if s and (s[-1] == p[-2] or p[-2] == '.') and self.isMatch(s[:-1], p):
                self.cache[(s, p)] = True
                return True
        if s and (s[-1] == p[-1] or p[-1] == '.') and self.isMatch(s[:-1], p[:-1]):
            self.cache[(s, p)] = True
            return True
        self.cache[(s, p)] = False
        return False