/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 *
 * https://leetcode.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (43.76%)
 * Likes:    2178
 * Dislikes: 180
 * Total Accepted:    380K
 * Total Submissions: 866.6K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * Given an array with n objects colored red, white or blue, sort them in-place
 * so that objects of the same color are adjacent, with the colors in the order
 * red, white and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent the color red,
 * white, and blue respectively.
 *
 * Note: You are not suppose to use the library's sort function for this
 * problem.
 *
 * Example:
 *
 *
 * Input: [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 *
 * Follow up:
 *
 *
 * A rather straight forward solution is a two-pass algorithm using counting
 * sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then
 * overwrite array with total number of 0's, then 1's and followed by 2's.
 * Could you come up with a one-pass algorithm using only constant space?
 *
 *
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  void sortColors(vector<int> &nums) {
    if (nums.size() < 1) {
      return;
    }
    auto head = nums.begin();
    auto cur = head;
    auto tail = nums.end() - 1;
    while (cur <= tail) {
      switch (*cur) {
      case 0: {
        if (cur > head) {
          swap(*cur, *head);
        } else {
          cur++;
        }
        head++;
        break;
      }
      case 2: {
        if (cur < tail) {
          swap(*cur, *tail);
        } else {
          cur++;
        }
        tail--;
        break;
      }
      default:
        cur++;
      }
    }
  }
};
// @lc code=end
