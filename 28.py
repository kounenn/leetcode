class Solution:
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """

        if not needle:
            return 0
        sh = len(haystack)
        sn = len(needle)
        for i in range(sh-sn+1):
            cur = 0
            for j in range(i,sh):
                if haystack[j] != needle[cur]:
                    break
                cur+=1
                if cur == sn:
                    return i
        return -1