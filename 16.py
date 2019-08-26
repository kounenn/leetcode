class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        size = len(nums)
        res = nums[0]+nums[0+1]+nums[0+2]
        for i in range(size-2):
            if i>0 and nums[i]==nums[i-1]:
                continue
            l,r = i+1,size-1
            while l<r:
                s = nums[i]+nums[l]+nums[r]
                if s == target:
                    return s
                if abs(target-s)<abs(target-res):
                    res = s
                if s<target:
                    while l<r:
                        l+=1
                        if nums[l]!=nums[l-1]:
                            break
                elif s>target:
                    while l<r:
                        r-=1
                        if nums[r]!=nums[r+1]:
                            break
        return res