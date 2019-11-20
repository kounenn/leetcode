/*
 * @lc app=leetcode id=1122 lang=cpp
 *
 * [1122] Relative Sort Array
 *
 * https://leetcode.com/problems/relative-sort-array/description/
 *
 * algorithms
 * Easy (66.45%)
 * Likes:    291
 * Dislikes: 20
 * Total Accepted:    29.3K
 * Total Submissions: 44.1K
 * Testcase Example:  '[2,3,1,3,2,4,6,7,9,2,19]\n[2,1,4,3,9,6]'
 *
 * Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all
 * elements in arr2 are also in arr1.
 *
 * Sort the elements of arr1 such that the relative ordering of items in arr1
 * are the same as in arr2.  Elements that don't appear in arr2 should be
 * placed at the end of arr1 in ascending order.
 *
 *
 * Example 1:
 * Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
 * Output: [2,2,2,1,4,3,3,9,6,7,19]
 *
 *
 * Constraints:
 *
 *
 * arr1.length, arr2.length <= 1000
 * 0 <= arr1[i], arr2[i] <= 1000
 * Each arr2[i] is distinct.
 * Each arr2[i] is in arr1.
 *
 *
 */

#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
    unordered_map<int, int> idx_map;
    for (int i = 0; i < arr2.size(); i++) {
      idx_map[arr2[i]] = i;
    }
    sort(arr1.begin(), arr1.end(), [&idx_map](int x, int y) -> bool {
      bool has_x = idx_map.find(x) != idx_map.end();
      bool has_y = idx_map.find(y) != idx_map.end();
      if (has_x && has_y) {
        return idx_map[x] < idx_map[y];
      }
      if (!has_x && !has_y) {
        return x < y;
      }
      return has_x;
    });
    return arr1;
  }
};
// @lc code=end
