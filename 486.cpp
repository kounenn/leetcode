#include "header.h"
class Solution {
public:
  bool PredictTheWinner(vector<int> &nums) {
    if (nums.size() <= 1)
      return true;
    return score(nums.begin(), nums.end() - 1) >= 0;
  }
  int score(vector<int>::const_iterator beg, vector<int>::const_iterator end) {
    if (beg == end) {
      return *beg;
    }
    return max(*beg - score(beg + 1, end), *(end)-score(beg, end - 1));
  }
};
