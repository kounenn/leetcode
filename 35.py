class Solution:
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        
        l = 0
        r = len(nums)-1
        
        if nums[l]>=target:
            return l

        if nums[r]<target:
            return r+1
            

        while r-l>=2:
            mid = (l+r)//2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                l=mid
            else:
                r=mid
        return r

if __name__ == '__main__':
    main()