#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    vector<string> res;
    for (auto &w : words) {
      if (exist(board, w)) {
        res.push_back(w);
      }
    }
    return res;
  }

  bool exist(vector<vector<char>> &board, string const &word) {
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (dfs(i, j, board, word.c_str())) {
          return true;
        }
      }
    }
    return false;
  }

  bool dfs(int row, int col, vector<vector<char>> &board, char const *cp) {
    if (*cp == '\0') {
      return true;
    }
    if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() ||
        board[row][col] != *cp) {
      return false;
    }
    board[row][col] = '#';

    int rows[4] = {row + 1, row, row - 1, row};
    int cols[4] = {col, col + 1, col, col - 1};

    bool ok = false;
    for (int i = 0; i < 4; i++) {
      ok = dfs(rows[i], cols[i], board, cp + 1);
      if (ok) {
        break;
      }
    }
    board[row][col] = *cp;
    return ok;
  }
};