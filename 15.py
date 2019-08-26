class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """

        nums.sort()
        result = []
        size = len(nums)

        for i in range(size-2):
            if i>0 and nums[i] == nums[i-1]:
                continue
            l,r = i+1,size-1
            while l<r:
                s = nums[i]+nums[l]+nums[r]
                if s>0:
                    r-=1
                elif s<0:
                    l+=1
                else:
                    result.append([nums[i],nums[l],nums[r]])
                    while l<r and nums[r]==nums[r-1]:#先判断l<r,防止越界
                        r-=1
                    while l<r and nums[l]==nums[l+1]:
                        l+=1
                    l+=1
                    r-=1
        return result