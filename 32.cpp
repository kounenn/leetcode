#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  int longestValidParentheses(string s) {
    stack<int> st;
    int start = 0;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        st.push(i);
      } else {
        if (st.size() == 0) {
          start = i + 1;
        } else {
          st.pop();
          if (st.size() == 0) {
            ans = max(ans, i - start + 1);
          } else {
            ans = max(ans, i - st.top()); //(*()的情况，长度为为i-(st.top()+1)+1=i-st.top()
          }
        }
      }
    }
    return ans;
  }
};