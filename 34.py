class Solution:
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

        size = len(nums)
        left = 0
        right = size - 1
        pivot = -1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                pivot = mid
                break
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        i = j = pivot
        while i > 0 and nums[i - 1] == nums[i]:
            i -= 1
        while j >= 0 and j < size - 1 and nums[j] == nums[j + 1]:
            j += 1

        return i, j
