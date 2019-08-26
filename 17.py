class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        
        d2l={
            '1':[''],
            '2':['a','b','c'],
            '3':['d','e','f'],
            '4':['g','h','i'],
            '5':['j','k','l'],
            '6':['m','n','o'],
            '7':['p','q','r','s'],
            '8':['t','u','v'],
            '9':['w','x','y','z'],
            '0':[' ']
        }
        return reduce(lambda acc,d:[i+j for i in acc for j in d2l[d]],digits,['']) if digits else []