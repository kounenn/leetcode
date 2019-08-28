#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
  int result = 0;

public:
  int uniquePathsIII(vector<vector<int>> &grid) {
    int row, col, remainder = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] != -1) {
          remainder++;
        }
        if (grid[i][j] == 1) {
          row = i;
          col = j;
        }
      }
    };

    dfs(row, col, grid, remainder);
    return result;
  }

  void dfs(int row, int col, vector<vector<int>> &grid, int remainder) {
    if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() ||
        grid[row][col] == -1) {
      return;
    }

    remainder--;

    if (grid[row][col] == 2) {
      if (remainder == 0) {
        result++;
      }
      return;
    }

    grid[row][col] = -1;
    dfs(row + 1, col, grid, remainder);
    dfs(row - 1, col, grid, remainder);
    dfs(row, col + 1, grid, remainder);
    dfs(row, col - 1, grid, remainder);
    grid[row][col] = 0;
  }
};