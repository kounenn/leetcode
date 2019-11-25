/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (49.44%)
 * Likes:    1793
 * Dislikes: 46
 * Total Accepted:    280.5K
 * Total Submissions: 565.9K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 * Example:
 *
 *
 * Input:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 *
 *
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size();
    if (m < 1) {
      return 0;
    }
    int n = grid[0].size();
    if (n < 1) {
      return 0;
    }
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[m - 1][n - 1] = grid[m - 1][n - 1];
    for (int j = n - 2; j >= 0; j--) {
      dp[m - 1][j] = grid[m - 1][j] + dp[m - 1][j + 1];
    }
    for (int i = m - 2; i >= 0; i--) {
      dp[i][n - 1] = grid[i][n - 1] + dp[i + 1][n - 1];
    }
    for (int i = m - 2; i >= 0; i--) {
      for (int j = n - 2; j >= 0; j--) {
        dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
      }
    }
    return dp[0][0];
  }
};
// @lc code=end
