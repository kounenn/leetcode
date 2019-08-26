class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        s = str.strip()
        if not s:
            return 0
        l = len(s)
        i = 0
        op = 1
        if s[i]=='-':
            i+=1
            op=-1
        elif s[i] == '+':
            i+=1
        if i>=l:
            return 0
        if not s[i].isdigit():
            return 0

        num = 0
        while i<l:
            if not s[i].isdigit():
                break
            num = num*10+int(s[i])
            i+=1
        num *= op
        MAX_INT = pow(2,31)-1
        MIN_INT = -(MAX_INT+1)
        if num > MAX_INT:
            return MAX_INT
        elif num < MIN_INT:
            return MIN_INT
        else:
            return num