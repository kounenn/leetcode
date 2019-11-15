/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (44.31%)
 * Likes:    1163
 * Dislikes: 56
 * Total Accepted:    233.7K
 * Total Submissions: 527.4K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Example:
 *
 *
 * Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 *
 *
 */

#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  void backtrack(vector<vector<int>> &r, vector<int> &cur,
                 vector<int>::const_iterator pos,
                 vector<int>::const_iterator end) {
    r.push_back(cur);
    for (auto it = pos; it < end; it++) {
      if (it > pos && *it == *(it - 1)) {
        continue;
      }
      cur.push_back(*it);
      backtrack(r, cur, it + 1, end);
      cur.pop_back();
    }
  }

public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<vector<int>> r;
    vector<int> cur;
    sort(nums.begin(), nums.end());
    backtrack(r, cur, nums.begin(), nums.end());
    return r;
  }
};
// @lc code=end
