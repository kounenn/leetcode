/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (45.88%)
 * Likes:    578
 * Dislikes: 182
 * Total Accepted:    236.3K
 * Total Submissions: 514K
 * Testcase Example:  '3'
 *
 * Given a non-negative index k where k ≤ 33, return the k^th index row of the
 * Pascal's triangle.
 *
 * Note that the row index starts from 0.
 *
 *
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 *
 * Example:
 *
 *
 * Input: 3
 * Output: [1,3,3,1]
 *
 *
 * Follow up:
 *
 * Could you optimize your algorithm to use only O(k) extra space?
 *
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> r(rowIndex + 1, 0);
    if (rowIndex < 0) {
      return r;
    }
    r[0] = 1;
    for (int i = 1; i <= rowIndex; i++) {
      r[i] = 1;
      for (int j = i - 1; j - 1 >= 0; j--) {
        r[j] += r[j - 1];
      }
    }
    return r;
  }
};
// @lc code=end
