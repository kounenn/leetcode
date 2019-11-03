#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
    vector<string> r;
    vector<int> m1(26, -1);
    vector<int> m2(26, -1);
    for (auto &w : words) {
      if (match_string(w, pattern, m1, m2)) {
        r.push_back(w);
      }
    }
    return r;
  }

  bool match_string(string const &s, string const &p, vector<int> &m1,
                    vector<int> &m2) {
    fill(m1.begin(), m1.end(), -1);
    fill(m2.begin(), m2.end(), -1);
    auto size = s.size();
    for (int i = 0; i < size; i++) {
      if (!match_char(s[i] - 'a', p[i] - 'a', m1, m2)) {
        return false;
      }
    }
    return true;
  }

  bool match_char(int n1, int n2, vector<int> &m1, vector<int> &m2) {
    if (m1[n1] == -1) {
      m1[n1] = n2;
    }
    if (m2[n2] == -1) {
      m2[n2] = n1;
    }
    if (m1[n1] == n2 && m2[n2] == n1) {
      return true;
    }
    return false;
  }
};