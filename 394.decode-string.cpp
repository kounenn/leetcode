/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (47.14%)
 * Likes:    2136
 * Dislikes: 115
 * Total Accepted:    148K
 * Total Submissions: 313.3K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * Given an encoded string, return its decoded string.
 *
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 *
 * You may assume that the input string is always valid; No extra white spaces,
 * square brackets are well-formed, etc.
 *
 * Furthermore, you may assume that the original data does not contain any
 * digits and that digits are only for those repeat numbers, k. For example,
 * there won't be input like 3a or 2[4].
 *
 * Examples:
 *
 *
 * s = "3[a]2[bc]", return "aaabcbc".
 * s = "3[a2[c]]", return "accaccacc".
 * s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 *
 *
 *
 *
 */

#include <cctype>
#include <sstream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
  string decodeString(string s) {
    stringstream r;
    int size = s.size();
    for (int i = 0; i < size;) {
      for (; i < size && isalpha(s[i]); i++) {
        r << s[i];
      }
      if (i == size) {
        break;
      }
      int n = 0;
      for (; isdigit(s[i]); i++) {
        n = 10 * n + (s[i] - '0');
      }
      int dlim_num = 1;
      int start = ++i;
      for (; dlim_num > 0; i++) {
        if (s[i] == '[') {
          dlim_num++;
        } else if (s[i] == ']') {
          dlim_num--;
        }
      }
      int end = i - 1;
      for (int i = 0; i < n; i++) {
        r << decodeString(string(s.cbegin() + start, s.cbegin() + end));
      }
    }
    return r.str();
  }
};
// @lc code=end
