/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (16.17%)
 * Likes:    851
 * Dislikes: 4082
 * Total Accepted:    228.8K
 * Total Submissions: 1.4M
 * Testcase Example:  '10\n3'
 *
 * Given two integers dividend and divisor, divide two integers without using
 * multiplication, division and mod operator.
 *
 * Return the quotient after dividing dividend by divisor.
 *
 * The integer division should truncate toward zero.
 *
 * Example 1:
 *
 *
 * Input: dividend = 10, divisor = 3
 * Output: 3
 *
 * Example 2:
 *
 *
 * Input: dividend = 7, divisor = -3
 * Output: -2
 *
 * Note:
 *
 *
 * Both dividend and divisor will be 32-bit signed integers.
 * The divisor will never be 0.
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 2^31 − 1 when the
 * division result overflows.
 *
 *
 */

#include <cstdint>

// @lc code=start
class Solution {
public:
  int divide(int dividend, int divisor) {
    bool s = false;
    if (divisor == 0)
      return INT_MAX;
    if (divisor == 1) {
      return dividend;
    }
    if (divisor == -1) {
      if (dividend == -INT_MAX - 1) {
        return INT_MAX;
      } else {
        return -dividend;
      }
    }
    s = (dividend < 0) ^ (divisor < 0) ? true : false;
    int res = 0;
    long long d1 = labs(dividend);
    long long d2 = labs(divisor);
    while (d1 >= d2) {
      int i = 1;
      long long temp = labs(d2);
      while (temp << 1 <= d1) {
        i *= 2;
        temp <<= 1;
      }
      d1 -= temp;
      res += i;
    }
    if (s) {
      res = -res;
    }
    return res;
  }
};
// @lc code=end
