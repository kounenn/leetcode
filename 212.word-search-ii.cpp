/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 *
 * https://leetcode.com/problems/word-search-ii/description/
 *
 * algorithms
 * Hard (30.88%)
 * Likes:    1574
 * Dislikes: 84
 * Total Accepted:    146.4K
 * Total Submissions: 472.1K
 * Testcase Example:
 '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n' +
  '["oath","pea","eat","rain"]'
 *
 * Given a 2D board and a list of words from the dictionary, find all words in
 * the board.
 *
 * Each word must be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once in a word.
 *
 *
 *
 * Example:
 *
 *
 * Input:
 * board = [
 * ⁠ ['o','a','a','n'],
 * ⁠ ['e','t','a','e'],
 * ⁠ ['i','h','k','r'],
 * ⁠ ['i','f','l','v']
 * ]
 * words = ["oath","pea","eat","rain"]
 *
 * Output: ["eat","oath"]
 *
 *
 *
 *
 * Note:
 *
 *
 * All inputs are consist of lowercase letters a-z.
 * The values of words are distinct.
 *
 *
 */

#include <map>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  void dfs(unordered_set<string> &r, vector<vector<char>> &board, int i, int j,
           vector<string> const &words, vector<int> indexs) {
    if (i >= board.size() || j >= board[0].size()) {
      return;
    }
    auto c = board[i][j];
    int n = indexs.size();
    for (int i = 0; i < indexs.size(); i++) {
      if (indexs[i] < 0) {
        n--;
        continue;
      }
      if (words[i][indexs[i]] != c) {
        indexs[i] = -1;
        n--;
        continue;
      }
      indexs[i]++;
      if (indexs[i] >= words[i].size()) {
        indexs[i] = -1;
        n--;
        r.insert(words[i]);
      }
    }
    if (n <= 0) {
      return;
    }
    board[i][j] = '#';
    dfs(r, board, i + 1, j, words, indexs);
    dfs(r, board, i - 1, j, words, indexs);
    dfs(r, board, i, j + 1, words, indexs);
    dfs(r, board, i, j - 1, words, indexs);
    board[i][j] = c;
  }

public:
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    unordered_set<string> r;
    vector<int> indexs(words.size(), 0);
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        dfs(r, board, i, j, words, indexs);
      }
    }
    return vector<string>(r.cbegin(), r.cend());
  }
};
// @lc code=end
