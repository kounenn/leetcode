#include <random>
#include <vector>

using namespace std;

class Solution {
private:
  vector<int> &m_nums;

public:
  Solution(vector<int> &nums) : m_nums(nums) {}

  int pick(int target) {
    random_device rd;
    default_random_engine e(rd());

    int k = 0, res = -1;
    for (int i = 0; i < m_nums.size(); i++) {
      if (m_nums[i] == target) {
        k++;
        if (k == 1) {
          res = i;
        } else {
          uniform_int_distribution<int> dist(1, k);
          if (dist(e) == 1) {
            res = i;
          }
        }
      }
    }
    return res;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */