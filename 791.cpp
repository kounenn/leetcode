#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  string customSortString(string S, string T) {
    string r;
    r.resize(T.size());
    int cur = 0;
    vector<int> vec(T.size(), 0);
    unordered_map<char, int> m;

    for (auto c : S) {
      m[c] = 0;
    }
    for (auto c : T) {
      if (m.find(c) != m.end()) {
        m[c]++;
      }
    }

    for (auto c : S) {
      auto count = m[c];
      for (int i = 0; i < count; i++) {
        r[cur++] = c;
      }
    }
    for (auto c : T) {
      if (m.find(c) != m.end()) {
        continue;
      }
      r[cur++] = c;
    }
    return r;
  }
};