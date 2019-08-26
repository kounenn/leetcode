class Solution:
    def floodFill(self, image, sr, sc, newColor):
        """
        :type image: List[List[int]]
        :type sr: int
        :type sc: int
        :type newColor: int
        :rtype: List[List[int]]
        """

        oldColor = image[sr][sc] 
        image[sr][sc] = newColor

        if oldColor == newColor:# 防止无穷递归
            return image
        
        def fill(image,sr,sc):
            if sr>=len(image) or sr<0 or sc>=len(image[0]) or sc<0:
                return
            if image[sr][sc] == oldColor:
                image[sr][sc] = newColor
                fill(image,sr+1,sc)
                fill(image,sr-1,sc)
                fill(image,sr,sc+1)
                fill(image,sr,sc-1)
            return
        fill(image,sr+1,sc)
        fill(image,sr-1,sc)
        fill(image,sr,sc+1)
        fill(image,sr,sc-1)

        return image

print(Solution().floodFill([[0,0,0],[0,1,1]],1,1,1))