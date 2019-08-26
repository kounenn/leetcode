class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        common = min(strs,key=lambda s:len(s)) if strs else []           
        i = 0
        r = False
        for i in range(len(common)):
            for st in strs:
                if common[i]!=st[i]:
                    i-=1
                    r = True
                    break
            if r:
                break
                    
        return ''.join(common[:i+1])