#include <string>
#include <vector>
using namespace std;

class Solution {
private:
  bool result = false;

public:
  bool exist(vector<vector<char>> &board, string word) {
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        dfs(i, j, board, word.c_str(), word.length());
      }
    }
    return result;
  }

  void dfs(int row, int col, vector<vector<char>> &board, const char *cp,
           size_t n) {
    if (result) {
      return;
    }

    if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() ||
        board[row][col] != *cp || n == 0) {
      return;
    }
    n--;
    if (n == 0) {
      result = true;
      return;
    }

    board[row][col] = '#';
    dfs(row + 1, col, board, cp + 1, n);
    dfs(row, col + 1, board, cp + 1, n);
    dfs(row - 1, col, board, cp + 1, n);
    dfs(row, col - 1, board, cp + 1, n);
    board[row][col] = *cp;

    return;
  }
};