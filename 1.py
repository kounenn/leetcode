class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        n = nums[:]
        nums.sort()
        l = len(nums)
        x = 0
        j = l-1
        while True:
            a = nums[x]
            b = nums[j]

            if a+b == target:
                for x in range(l):
                    if n[x] == a:
                        if n[x] == b:
                            for y in range(x+1,l):
                                if n[y] == b:
                                    return (x,y)
                        else:
                            for y in range(l):
                                if n[y] == b:
                                    if x>y:
                                        x,y = y,x
                                    return (x,y)
            elif a + b < target:
                x+=1
            else:
                j-=1