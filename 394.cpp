#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
  string decodeString(string s) {
    stringstream res;
    auto size = s.size();
    for (int i = 0; i < size;) {
      for (; isalpha(s[i]) && i < size; i++) {
        res << s[i];
      }
      if (i == size) {
        break;
      }
      int n = 0;
      for (; isdigit(s[i]); i++) {
        n = 10 * n + s[i] - '0';
      }
      if (n == 0) {
        continue;
      }
      stringstream ss;
      int dlim_num = 0;
      do {
        if (s[i] == '[') {
          dlim_num++;
        } else if (s[i] == ']') {
          dlim_num--;
        }
        ss << s[i];
        i++;
      } while (dlim_num > 0);

      string str(ss.str());
      if (str.size() < 2) {
        continue;
      }
      auto sub_res = decodeString(string(str.begin() + 1, str.end() - 1));
      for (int j = 0; j < n; j++) {
        res << sub_res;
      }
    }
    return res.str();
  }
};