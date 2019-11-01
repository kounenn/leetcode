#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    auto ita = a.crbegin();
    auto itb = b.crbegin();
    vector<char> res;
    int flag = 0;
    for (; ita != a.crend() && itb != b.crend(); ita++, itb++) {
      int n = *ita - '0';
      n += *itb - '0';
      n += flag;
      if (n > 1) {
        n -= 2;
        flag = 1;
      } else {
        flag = 0;
      }
      res.push_back('0' + n);
    }
    string::const_reverse_iterator begin, end;
    if (a.size() > b.size()) {
      begin = ita;
      end = a.crend();
    } else {
      begin = itb;
      end = b.crend();
    }
    for (; begin != end; begin++) {
      int n = (*begin - '0') + flag;
      if (n > 1) {
        n -= 2;
        flag = 1;
      } else {
        flag = 0;
      }
      res.push_back('0' + n);
    }
    if (flag > 0) {
      res.push_back('0' + flag);
    }
    return string(res.rbegin(), res.rend());
  }
};