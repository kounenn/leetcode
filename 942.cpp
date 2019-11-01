#include <deque>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> diStringMatch(string S) {
    deque<int> q;
    vector<int> ans;
    for (int i = 0; i < S.size() + 1; i++) {
      q.push_back(i);
    }
    for (auto c : S) {
      if (c == 'I') {
        ans.push_back(q.front());
        q.pop_front();
      } else {
        ans.push_back(q.back());
        q.pop_back();
      }
    }
    ans.push_back(q.back());
    return ans;
  }
};