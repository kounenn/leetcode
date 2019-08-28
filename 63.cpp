#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    auto m = obstacleGrid.size();
    if (m < 1) {
      return 0;
    }
    auto n = obstacleGrid[0].size();
    if (n < 1) {
      return 0;
    }

    long dp[m][n];
    memset(dp, -1, sizeof(long) * m * n);

    dp[0][0] = 1;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (obstacleGrid[i][j] == 1) {
          dp[i][j] = 0;
        } else if (i == 0 && j > 0) {
          dp[i][j] = dp[i][j - 1];
        } else if (j == 0 && i > 0) {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (dp[i][j] == -1) {
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
      }
    }

    return dp[m - 1][n - 1];
  }
};