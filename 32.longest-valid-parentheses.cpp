/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (26.71%)
 * Likes:    2492
 * Dislikes: 110
 * Total Accepted:    229.8K
 * Total Submissions: 859.2K
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 *
 * Example 1:
 *
 *
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 *
 *
 * Example 2:
 *
 *
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 *
 *
 */

#include <stack>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
  int longestValidParentheses(string s) {
    stack<int> st;
    int r = 0;
    int start = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        st.push(i);
        continue;
      }
      if (st.empty()) {
        start = i + 1; //一个单独的(，下一个起始位置肯定在它后面
        continue;
      }
      st.pop();
      if (st.empty()) {
        r = max(r, i - start + 1); // (*)完全匹配的情况,长度为i - start + 1
        continue;
      }
      r = max(
          r,
          i - st.top()); // (*()非完全匹配的情况，长度为i- (st.top() + 1) + 1
    }
    return r;
  }
};
// @lc code=end