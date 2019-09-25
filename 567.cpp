#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    int l1 = s1.size();
    int l2 = s2.size();
    int remain = l1;
    unordered_map<char, int> m;

    for (auto c : s1) {
      if (m.find(c) != m.end()) {
        m[c]++;
      } else {
        m[c] = 1;
      }
    }

    if (l1 > l2) {
      return false;
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
      if (m.find(s2[j]) != m.end() && ++m[s2[j]] > 0) {
        remain++;
      }
      if (m.find(s2[i]) != m.end() && --m[s2[i]] >= 0) {
        remain--;
      }
      if (remain == 0) {
        return true;
      }
    }
    return false;
  }
};