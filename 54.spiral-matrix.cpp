/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (31.97%)
 * Likes:    1522
 * Dislikes: 465
 * Total Accepted:    287.9K
 * Total Submissions: 899.3K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 *
 * Example 1:
 *
 *
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 *
 *
 * Example 2:
 *
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 *
 */

#include <iterator>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int m_l = matrix.size();
    vector<int> r;
    if (m_l < 1) {
      return r;
    }
    int m_w = matrix[0].size();
    r.reserve(m_l * m_w);
    int d = 1;
    for (int i = 0, j = 0; m_l > 0 && m_w > 0;) {
      for (int k = 0; k < m_w; k++) {
        r.push_back(matrix[i][j]);
        j += d;
      }
      j -= d;
      m_l--;

      i += d;
      for (int k = 0; k < m_l; k++) {
        r.push_back(matrix[i][j]);
        i += d;
      }
      i -= d;
      m_w--;

      d *= -1;
      j += d;
    }
    return r;
  }
};
// @lc code=end
