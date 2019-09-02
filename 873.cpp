#include <vector>

using namespace std;

class Solution {

public:
  int lenLongestFibSubseq(vector<int> &A) {
    int i = A.size();
    int j = i;
    int dp[i][j];
    int res = 0;
    memset(dp, 0, i * j * sizeof(int));
    for (int j = 2; j < A.size(); j++) {
      for (int i = j - 1; i >= 0; i--) {
        int obj = A[j] - A[i], k = -1, l = 0, r = i;
        while (l < r) {
          int m = l + (r - l) / 2;
          if (A[m] == obj) {
            k = m;
            break;
          } else if (A[m] < obj) {
            l = m + 1;
          } else {
            r = m;
          }
        }
        if (k != -1) {
          dp[i][j] = dp[k][i] + 1;
          res = max(res, dp[i][j]);
        }
      }
    }
    return res > 0 ? res + 2 : res;
  }
};