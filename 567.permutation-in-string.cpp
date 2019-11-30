/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 *
 * https://leetcode.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (39.53%)
 * Likes:    869
 * Dislikes: 45
 * Total Accepted:    67K
 * Total Submissions: 169.3K
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * Given two strings s1 and s2, write a function to return true if s2 contains
 * the permutation of s1. In other words, one of the first string's
 * permutations is the substring of the second string.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: s1 = "ab" s2 = "eidbaooo"
 * Output: True
 * Explanation: s2 contains one permutation of s1 ("ba").
 *
 *
 * Example 2:
 *
 *
 * Input:s1= "ab" s2 = "eidboaoo"
 * Output: False
 *
 *
 *
 *
 * Note:
 *
 *
 * The input strings only contain lower case letters.
 * The length of both given strings is in range [1, 10,000].
 *
 *
 */

#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    int l1 = s1.size();
    int l2 = s2.size();
    if (l1 > l2) {
      return false;
    }
    int remain = 0;
    unordered_map<char, int> m;
    for (auto c : s1) {
      if (m.find(c) != m.end()) {
        m[c]++;
      } else {
        m[c] = 1;
      }
      remain++;
    }
    for (int i = 0; i < l1; i++) {
      if (m.find(s2[i]) != m.end() && --m[s2[i]] >= 0) {
        remain--;
      }
    }
    if (remain == 0) {
      return true;
    }
    for (int i = l1, j = 0; i < l2; i++, j++) {
      if (m.find(s2[i]) != m.end() && --m[s2[i]] >= 0) {
        remain--;
      }
      if (m.find(s2[j]) != m.end() && ++m[s2[j]] > 0) {
        remain++;
      }
      if (remain == 0) {
        return true;
      }
    }
    return false;
  }
};
// @lc code=end
