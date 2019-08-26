class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0 
        r = 0
        for i in range(1,len(nums)):
            if nums[i] != nums[r]:
                r+=1
                nums[r] = nums[i]
        return r+1

def main():
    s = Solution()
    nums = [1,1,1,1,2,2,2,3,3,4,5,5,6]
    print(nums[:s.removeDuplicates(nums)])
    print(nums)
    

if __name__ == '__main__':
    main()