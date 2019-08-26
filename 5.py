class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        # Manacher 算法,O(n)时间求字符串的最长回文子串

        s2 = '#'
        for i in range(len(s)):
            s2+=s[i]+'#'
        
        s = '$'+s2+'!' # 防止s越界
        l = len(s)
        p = [1]*(l-1) # p[i]是s[i]向右或向左扩张的长度(包含自身)
        sid = 1 # 初始为i=i时
        mx = sid+p[sid]
        for i in range(1,l-1):#不包括哨兵位置
            j = 2*sid-i # j是i关于sid的对称点

            # 当mx>i时,若mx-i>p[j],则因为i与j对称,所以以s[i]为中心的回文必在以s[sid]为中心的回文中,且p[i]=p[j],
            # 当mx-i<p[j]时,以s[i]为中心的回文有一部分在以s[sid]为中心的回文中
            # 当mx<i时,无法确定,只能从1开始验证
            p[i] = min(p[j], mx-i) if mx>i else 1
            while s[i+p[i]] == s[i-p[i]]:
                p[i]+=1
            if(i+p[i])>mx:
                sid=i
                mx = i+p[i]
        p = p[1:] # i从1开始
        r = max(p)-1
        ii = p.index(r+1)
        s = s[1:l-1]
        return s[ii-r:ii+r+1].replace('#','')