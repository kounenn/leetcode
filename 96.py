class Solution:
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        # 思路：每个结点i为根时，1-(i-1)组成左子树，(i+1)-n组成右子树，有numTrees(i-1)*numTress(n-i)种可能,numTrees(n)为其总和
        nums = [1 for i in range(n + 1)]
        for i in range(2, n + 1):
            nums[i] = 0
            for j in range(1, i + 1):
                nums[i] += nums[j - 1] * nums[i - j]
        return nums[n]
