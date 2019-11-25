/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (32.87%)
 * Likes:    2455
 * Dislikes: 130
 * Total Accepted:    357.4K
 * Total Submissions: 1.1M
 * Testcase Example:
 * '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 *
 * Example:
 *
 *
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 *
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 *
 *
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  bool dfs(vector<vector<char>> &board, int i, int j, char const *c) {
    if (*c == '\0') {
      return true;
    }
    if (i >= board.size() || j >= board[0].size() || board[i][j] != *c) {
      return false;
    }
    board[i][j] = '#';
    auto next = c + 1;
    bool ok = dfs(board, i + 1, j, next) || dfs(board, i - 1, j, next) ||
              dfs(board, i, j + 1, next) || dfs(board, i, j - 1, next);
    board[i][j] = *c;
    return ok;
  }

public:
  bool exist(vector<vector<char>> &board, string word) {
    if (word.size() < 1) {
      return true;
    }
    int m = board.size();
    if (m < 1) {
      return false;
    }
    int n = board[0].size();
    if (n < 1) {
      return false;
    }
    auto start = word.c_str();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (dfs(board, i, j, start)) {
          return true;
        }
      }
    }
    return false;
  }
};
// @lc code=end
