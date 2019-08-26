class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x<0:
            return False
        rx = 0
        while x:
            x,n = divmod(x,10)
            rx = 10*rx+n
        return True if rx==x else False
            
        