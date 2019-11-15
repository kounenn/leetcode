/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (56.23%)
 * Likes:    2545
 * Dislikes: 62
 * Total Accepted:    442.7K
 * Total Submissions: 787.2K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Example:
 *
 *
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 *
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  void backtrack(vector<vector<int>> &r, vector<int> &cur,
                 vector<int>::const_iterator pos,
                 vector<int>::const_iterator end) {
    r.push_back(cur);
    for (auto it = pos; it < end; it++) {
      cur.push_back(*it);
      backtrack(r, cur, it + 1, end);
      cur.pop_back();
    }
  }

public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> r;
    vector<int> cur;
    backtrack(r, cur, nums.begin(), nums.end());
    return r;
  }
};
// @lc code=end
