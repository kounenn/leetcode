/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 *
 * https://leetcode.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (33.76%)
 * Likes:    1126
 * Dislikes: 186
 * Total Accepted:    239.2K
 * Total Submissions: 708.6K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 *
 * Now consider if some obstacles are added to the grids. How many unique paths
 * would there be?
 *
 *
 *
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 *
 * Note: m and n will be at most 100.
 *
 * Example 1:
 *
 *
 * Input:
 * [
 * [0,0,0],
 * [0,1,0],
 * [0,0,0]
 * ]
 * Output: 2
 * Explanation:
 * There is one obstacle in the middle of the 3x3 grid above.
 * There are two ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down -> Down
 * 2. Down -> Down -> Right -> Right
 *
 *
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size();
    if (m < 1) {
      return 0;
    }
    int n = obstacleGrid[0].size();
    if (n < 1) {
      return 0;
    }
    vector<vector<long long>> dp(m, vector<long long>(n, 0));
    if (obstacleGrid[m - 1][n - 1] == 0) {
      dp[m - 1][n - 1] = 1;
    }
    for (int j = n - 2; j >= 0; j--) {
      if (obstacleGrid[m - 1][j] == 0) {
        dp[m - 1][j] = dp[m - 1][j + 1];
      }
    }
    for (int i = m - 2; i >= 0; i--) {
      if (obstacleGrid[i][n - 1] == 0) {
        dp[i][n - 1] = dp[i + 1][n - 1];
      }
    }

    for (int i = m - 2; i >= 0; i--) {
      for (int j = n - 2; j >= 0; j--) {
        if (obstacleGrid[i][j] == 1) {
          continue;
        }
        dp[i][j] += dp[i + 1][j];
        dp[i][j] += dp[i][j + 1];
      }
    }
    return dp[0][0];
  }
};
// @lc code=end
