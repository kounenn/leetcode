/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 *
 * https://leetcode.com/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (35.72%)
 * Likes:    1163
 * Dislikes: 40
 * Total Accepted:    138.5K
 * Total Submissions: 387.6K
 * Testcase Example:  '[2,3,2]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed. All houses at this place are
 * arranged in a circle. That means the first house is the neighbor of the last
 * one. Meanwhile, adjacent houses have security system connected and it will
 * automatically contact the police if two adjacent houses were broken into on
 * the same night.
 *
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 *
 * Example 1:
 *
 *
 * Input: [2,3,2]
 * Output: 3
 * Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money
 * = 2),
 * because they are adjacent houses.
 *
 *
 * Example 2:
 *
 *
 * Input: [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money =
 * 3).
 * Total amount you can rob = 1 + 3 = 4.
 *
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
  int dp(vector<int> &nums, int start, int stop) {
    int sum = nums[start], pre_sum = 0;
    for (int i = start + 1; i < stop; i++) {
      int temp = sum;
      sum = max(sum, pre_sum + nums[i]);
      pre_sum = temp;
    }
    return sum;
  }

public:
  int rob(vector<int> &nums) {
    if (nums.size() < 1) {
      return 0;
    }
    if (nums.size() < 2) {
      return nums[0];
    }
    return max(dp(nums, 0, nums.size() - 1), dp(nums, 1, nums.size()));
  }
};
// @lc code=end
