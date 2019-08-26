class Solution:
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if not nums:
            return -1

        size = len(nums)
        pivot = size - 1
        for i in range(size - 1):
            if nums[i] > nums[i + 1]:
                pivot = i
                break
        if target >= nums[0]:
            left = 0
            right = pivot
        else:
            left = pivot + 1
            right = size - 1

        while left <= right:
            mid = (left + right) // 2
            if target == nums[mid]:
                return mid
            elif target > nums[mid]:
                left = mid + 1
            else:
                right = mid - 1

        return -1
