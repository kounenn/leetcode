class Solution:
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """

        w = len(matrix)
        if w <= 1:
            return
        for j in range(w):
            for i in range(j, w):
                matrix[j][i], matrix[i][j] = matrix[i][j], matrix[j][i]
        for i in range(w):
            for j in range(w//2):
                matrix[i][j], matrix[i][w-j-1] = matrix[i][w-j-1], matrix[i][j]
