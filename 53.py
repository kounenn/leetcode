class Solution:
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        MIN =-65535
        size = len(nums)
        if size == 1:
            return nums[0]
        if size == 0:
            return -MIN

        mid = size//2 
        
        max_left_sum = self.maxSubArray(nums[:mid])
        max_right_sum = self.maxSubArray(nums[mid:])

        max_board_left_sum = MIN     
        left_sum = 0
        for i in range(mid-1,-1,-1):
            left_sum+=nums[i]
            if left_sum>max_board_left_sum:
                max_board_left_sum = left_sum

        max_board_right_sum = MIN     
        right_sum = 0
        for i in range(mid,size):
            right_sum+=nums[i]
            if right_sum>max_board_right_sum:
                max_board_right_sum = right_sum
        
        s = max_board_left_sum+max_board_right_sum
        return max([max_left_sum,max_right_sum,s])