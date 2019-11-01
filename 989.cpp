#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> addToArrayForm(vector<int> &A, int K) {
    return arrayADD(A, intToArray(K));
  }

  vector<int> intToArray(int n) {
    vector<int> r;
    while (n > 0) {
      r.push_back(n % 10);
      n /= 10;
    }
    reverse(r.begin(), r.end());
    return r;
  }
  vector<int> arrayADD(vector<int> const &a, vector<int> const &b) {
    vector<int> r;
    int carry = 0;
    auto ita = a.crbegin(), itb = b.crbegin();
    for (; ita != a.crend() && itb != b.crend(); ita++, itb++) {
      int n = carry + *ita + *itb;
      carry = n / 10;
      n %= 10;
      r.push_back(n);
    }
    decltype(ita) begin, end;
    if (ita != a.crend()) {
      begin = ita;
      end = a.crend();
    } else {
      begin = itb;
      end = b.crend();
    }
    for (; begin != end; begin++) {
      int n = carry + *begin;
      carry = n / 10;
      n %= 10;
      r.push_back(n);
    }
    if (carry > 0) {
      r.push_back(carry);
    }
    reverse(r.begin(), r.end());
    return r;
  }
};