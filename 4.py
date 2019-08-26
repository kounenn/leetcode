class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        
        nums3 = nums1+nums2
        nums3.sort()
        l = len(nums3)
        if l%2==0:
            return (nums3[l//2-1]+nums3[l//2])/2
        else:
            return nums3[l//2]