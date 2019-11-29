/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 *
 * https://leetcode.com/problems/is-subsequence/description/
 *
 * algorithms
 * Easy (47.64%)
 * Likes:    770
 * Dislikes: 153
 * Total Accepted:    119.5K
 * Total Submissions: 250.7K
 * Testcase Example:  '"abc"\n"ahbgdc"'
 *
 *
 * Given a string s and a string t, check if s is subsequence of t.
 *
 *
 *
 * You may assume that there is only lower case English letters in both s and
 * t. t is potentially a very long (length ~= 500,000) string, and s is a short
 * string (
 *
 *
 * A subsequence of a string is a new string which is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters. (ie, "ace" is a
 * subsequence of "abcde" while "aec" is not).
 *
 *
 * Example 1:
 * s = "abc", t = "ahbgdc"
 *
 *
 * Return true.
 *
 *
 * Example 2:
 * s = "axc", t = "ahbgdc"
 *
 *
 * Return false.
 *
 *
 * Follow up:
 * If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you
 * want to check one by one to see if T has its subsequence. In this scenario,
 * how would you change your code?
 *
 * Credits:Special thanks to @pbrother for adding this problem and creating all
 * test cases.
 */
#include <algorithm>
#include <array>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  bool isSubsequence(string s, string t) {
    array<vector<int>, 26> indexs;
    for (int i = 0; i < t.size(); i++) {
      indexs[t[i] - 'a'].push_back(i);
    }
    if (s.size() < 1) {
      return true;
    }
    int pre = -1;
    for (int i = 0; i < s.size(); i++) {
      auto &idx = indexs[s[i] - 'a'];
      auto it = upper_bound(idx.cbegin(), idx.cend(), pre);
      if (it == idx.end()) {
        return false;
      }
      pre = *it;
    }
    return true;
  }
};
// @lc code=end
