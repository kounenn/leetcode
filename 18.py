class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        nums.sort()
        result = []
        size = len(nums)
        for i in range(size-3):
            for j in range(i+1,size-1):
                l=j+1
                r=size-1
                while l<r:
                    x1=nums[i]
                    x2=nums[j]
                    x3=nums[l]
                    x4=nums[r]
                    s = x1+x2+x3+x4
                    if s>target:
                        r-=1
                    elif s<target:
                        l+=1
                    else:
                        res = [x1,x2,x3,x4]
                        if not res in result:
                            result.append(res)
                        l+=1
                        r-=1
        return list(result)