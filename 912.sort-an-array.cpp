/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 *
 * https://leetcode.com/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (62.84%)
 * Likes:    191
 * Dislikes: 152
 * Total Accepted:    35.6K
 * Total Submissions: 56.7K
 * Testcase Example:  '[5,2,3,1]'
 *
 * Given an array of integers nums, sort the array in ascending order.
 *
 *
 * Example 1:
 * Input: nums = [5,2,3,1]
 * Output: [1,2,3,5]
 * Example 2:
 * Input: nums = [5,1,1,2,0,0]
 * Output: [0,0,1,1,2,5]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 50000
 * -50000 <= nums[i] <= 50000
 *
 *
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
  int pick_piv(vector<int> &nums) { return 0; }
  void swap(vector<int> &nums, int i, int j) {
    auto temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }
  void sort(vector<int> &nums, int l, int u) {
    if (l >= u) {
      return;
    }
    int m = l;
    int piv = nums[l];
    for (int i = l + 1; i < u; i++) {
      if (nums[i] < piv) {
        swap(nums, ++m, i);
      }
    }
    swap(nums, l, m);
    sort(nums, l, m);
    sort(nums, m + 1, u);
  }

public:
  vector<int> sortArray(vector<int> &nums) {
    int size = nums.size();
    if (size < 2) {
      return nums;
    }
    int piv = pick_piv(nums);
    sort(nums, piv, size);
    return nums;
  }
};
// @lc code=end
