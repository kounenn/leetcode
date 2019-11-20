/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 *
 * https://leetcode.com/problems/sort-array-by-parity/description/
 *
 * algorithms
 * Easy (73.05%)
 * Likes:    614
 * Dislikes: 62
 * Total Accepted:    142.2K
 * Total Submissions: 194.6K
 * Testcase Example:  '[3,1,2,4]'
 *
 * Given an array A of non-negative integers, return an array consisting of all
 * the even elements of A, followed by all the odd elements of A.
 *
 * You may return any answer array that satisfies this condition.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [3,1,2,4]
 * Output: [2,4,3,1]
 * The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= A.length <= 5000
 * 0 <= A[i] <= 5000
 *
 *
 *
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
  bool is_even(int n) {
    if (n == 1) {
      return false;
    }
    return n % 2 == 0;
  }

public:
  vector<int> sortArrayByParity(vector<int> &A) {
    int size = A.size();
    if (size < 1) {
      return A;
    }
    for (int i = 0, j = size - 1; i < j;) {
      if (is_even(A[i])) {
        i++;
        continue;
      }
      auto temp = A[j];
      A[j] = A[i];
      A[i] = temp;
      j--;
    }
    return A;
  }
};
// @lc code=end
