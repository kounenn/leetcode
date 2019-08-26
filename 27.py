class Solution:
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        
        r = 0
        for i in range(len(nums)):
            if nums[i] != val:
                nums[r] = nums[i]
                r+=1
        return r