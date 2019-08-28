#include <cstdlib>
#include <numeric>
#include <vector>

using namespace std;
class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size();
    if (m < 1) {
      return 0;
    }
    int n = grid[0].size();
    if (n < 1) {
      return accumulate(grid[0].begin(), grid[0].end(), 0);
    }

    long dp[m][n];
    memset(dp, -1, sizeof(long) * m * n);

    dp[0][0] = grid[0][0];
    for (int i = 1; i < m; i++) {
      dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int j = 1; j < n; j++) {
      dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (dp[i][j] == -1) {
          dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    return dp[m - 1][n - 1];
  }
};