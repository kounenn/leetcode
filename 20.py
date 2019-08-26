class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        m = {
            "{": "}",
            "(": ")",
            "[": "]"
        }
        stack = []
        for c in s:
            if c in m.keys():
                stack.append(c)
            elif c in m.values():
                if not stack or c != m[stack.pop()]:
                    return False
        return not stack
