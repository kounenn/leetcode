/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (50.69%)
 * Likes:    1019
 * Dislikes: 58
 * Total Accepted:    238.7K
 * Total Submissions: 470.9K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 *
 * Example:
 *
 *
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 *
 *
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  void backtrack(vector<vector<int>> &r, vector<int> &v, int pos, int n,
                 int k) {
    auto size = v.size();
    if (size + (n - pos + 1) < k) {
      return;
    }
    if (size == k) {
      r.push_back(v);
      return;
    }
    for (int i = pos; i <= n; i++) {
      v.push_back(i);
      backtrack(r, v, i + 1, n, k);
      v.pop_back();
    }
  }

public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> r;
    vector<int> v;
    v.reserve(k);
    backtrack(r, v, 1, n, k);
    return r;
  }
};
// @lc code=end
