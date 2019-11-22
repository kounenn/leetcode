/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 *
 * https://leetcode.com/problems/max-area-of-island/description/
 *
 * algorithms
 * Medium (59.51%)
 * Likes:    1355
 * Dislikes: 65
 * Total Accepted:    108.8K
 * Total Submissions: 182.6K
 * Testcase Example:  '[[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]'
 *
 * Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's
 * (representing land) connected 4-directionally (horizontal or vertical.) You
 * may assume all four edges of the grid are surrounded by water.
 *
 * Find the maximum area of an island in the given 2D array. (If there is no
 * island, the maximum area is 0.)
 *
 * Example 1:
 *
 *
 * [[0,0,1,0,0,0,0,1,0,0,0,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
 * ⁠[0,1,1,0,1,0,0,0,0,0,0,0,0],
 * ⁠[0,1,0,0,1,1,0,0,1,0,1,0,0],
 * ⁠[0,1,0,0,1,1,0,0,1,1,1,0,0],
 * ⁠[0,0,0,0,0,0,0,0,0,0,1,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,0,0,0,0]]
 *
 * Given the above grid, return 6. Note the answer is not 11, because the
 * island must be connected 4-directionally.
 *
 * Example 2:
 *
 *
 * [[0,0,0,0,0,0,0,0]]
 * Given the above grid, return 0.
 *
 * Note: The length of each dimension in the given grid does not exceed 50.
 *
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
  int dfs(vector<vector<int>> &grid, int l, int w, int x, int y) {
    if (x >= w || x < 0) {
      return 0;
    }
    if (y >= l || y < 0) {
      return 0;
    }
    if (grid[x][y] == 0) {
      return 0;
    }
    grid[x][y] = 0;
    int s = 1;
    s += dfs(grid, l, w, x + 1, y);
    s += dfs(grid, l, w, x - 1, y);
    s += dfs(grid, l, w, x, y + 1);
    s += dfs(grid, l, w, x, y - 1);
    return s;
  }

public:
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int r = 0;
    int w = grid.size();
    if (w < 1) {
      return r;
    }
    int l = grid[0].size();
    for (int i = 0; i < w; i++) {
      for (int j = 0; j < l; j++) {
        vector<vector<int>> g(grid.cbegin(), grid.cend());
        r = max(r, dfs(g, l, w, i, j));
      }
    }
    return r;
  }
};
// @lc code=end
