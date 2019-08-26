class Solution:
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """

        size = len(nums)
        index = 0
        for i in range(size - 1, 0, -1):
            if nums[i - 1] < nums[i]:
                index = i
                for j in range(size - 1, i - 1, -1):
                    if nums[j] > nums[i - 1]:
                        nums[j], nums[i - 1] = nums[i - 1], nums[j]
                        break
                break
        for j in range(index, index + (size - index) // 2):
            nums[j], nums[size + index - j -
                          1] = nums[size + index - j - 1], nums[j]
