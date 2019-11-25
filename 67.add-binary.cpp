/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (41.26%)
 * Likes:    1251
 * Dislikes: 233
 * Total Accepted:    361.8K
 * Total Submissions: 874.7K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 *
 * The input strings are both non-empty and contains only characters 1 or 0.
 *
 * Example 1:
 *
 *
 * Input: a = "11", b = "1"
 * Output: "100"
 *
 * Example 2:
 *
 *
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 *
 */
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
  string addBinary(string a, string b) {
    string r;
    int carry = 0;
    for (auto s1 = a.crbegin(), s2 = b.crbegin();
         s1 != a.crend() || s2 != b.crend();) {
      int x = 0, y = 0;
      if (s1 != a.crend()) {
        x = *(s1++) - '0';
      }
      if (s2 != b.crend()) {
        y = *(s2++) - '0';
      }
      int n = x ^ y ^ carry;
      carry = (x + y + carry) >> 1;
      r.push_back(n + '0');
    }
    if (carry > 0) {
      r.push_back(carry + '0');
    }
    return string(r.crbegin(), r.crend());
  }
};
// @lc code=end
