class Solution:
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        i =len(s)-1
        r = 0
        
        while i>=0:
            if s[i] != ' ':
                break
            i-=1
        while i>=0:
            if s[i] == ' ':
                break
            r+=1
            i-=1
        return r