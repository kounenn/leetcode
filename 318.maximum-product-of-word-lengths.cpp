/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 *
 * https://leetcode.com/problems/maximum-product-of-word-lengths/description/
 *
 * algorithms
 * Medium (49.59%)
 * Likes:    642
 * Dislikes: 52
 * Total Accepted:    87.5K
 * Total Submissions: 176.3K
 * Testcase Example:  '["abcw","baz","foo","bar","xtfn","abcdef"]'
 *
 * Given a string array words, find the maximum value of length(word[i]) *
 * length(word[j]) where the two words do not share common letters. You may
 * assume that each word will contain only lower case letters. If no such two
 * words exist, return 0.
 *
 * Example 1:
 *
 *
 * Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
 * Output: 16
 * Explanation: The two words can be "abcw", "xtfn".
 *
 * Example 2:
 *
 *
 * Input: ["a","ab","abc","d","cd","bcd","abcd"]
 * Output: 4
 * Explanation: The two words can be "ab", "cd".
 *
 * Example 3:
 *
 *
 * Input: ["a","aa","aaa","aaaa"]
 * Output: 0
 * Explanation: No such pair of words.
 *
 *
 */

#include <numeric>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int maxProduct(vector<string> &words) {
    int size = words.size();
    if (size < 2) {
      return 0;
    }
    int sum = 0;
    vector<int> v(size, 0);
    for (int i = 0; i < size; i++) {
      v[i] =
          accumulate(words[i].cbegin(), words[i].cend(), 0,
                     [](int a, char c) -> int { return a | (1 << (c - 'a')); });
    }
    for (int i = 0; i < size; i++) {
      for (int j = i + 1; j < size; j++) {
        if ((v[i] & v[j]) == 0) {
          sum = max(sum, int(words[i].size() * words[j].size()));
        }
      }
    }
    return sum;
  }
};
// @lc code=end
