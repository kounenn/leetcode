class Solution:
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        h = w = 9
        a1 = [[False for i in range(w)]
              for i in range(h)]  # use to check per row
        a2 = [[False for i in range(w)]
              for i in range(h)]  # use to check per line
        a3 = [[False for i in range(w)]
              for i in range(h)]  # use to check per subbox

        size = len(board)
        for i in range(size):
            for j in range(size):
                if board[i][j] != '.':
                    n = int(board[i][j])-1  # number to array index
                    # map (i,j) to array index,e.g. (0,0) to 0, (4,3) to 4
                    k = i//3*3+j//3
                    if a1[i][n] or a2[j][n] or a3[k][n]:
                        return False
                    a1[i][n] = a2[j][n] = a3[k][n] = True
        return True
