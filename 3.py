class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        max_l = 1 if len(s) else 0
        ss = []
        for a in s:
            if not a in ss:
                ss.append(a)
            else:
                l = len(ss)
                if l>max_l:
                    max_l = l
                ss = ss[ss.index(a)+1:]
                ss.append(a)
        
        l = len(ss)
        if l>max_l:
            max_l = l
                    
        return max_l