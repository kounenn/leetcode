class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        
        if x>pow(2,31)-1 or x<-pow(2,31):
            return 0
        sym = 1 if x>=0 else -1
        x=abs(x)
        num = 0
        while x:
            x,y = divmod(x,10)
            num = 10*num+y
        
        if num>pow(2,31)-1 or x<-pow(2,31):
            return 0
        return num*sym