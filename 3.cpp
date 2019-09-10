#include <string>
#include <vector>

using namespace std;
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int max_length = 0;
    vector<char> ss;
    for (auto chr : s) {
      auto it = find(ss.begin(), ss.end(), chr);
      if (it == ss.end()) {
        ss.push_back(chr);
      } else {
        max_length = max(max_length, int(ss.size()));
        ss = vector<char>(it + 1, ss.end());
        ss.push_back(chr);
      }
    }
    max_length = max(max_length, int(ss.size()));
    return max_length;
  }
};