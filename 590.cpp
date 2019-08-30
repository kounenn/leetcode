#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
public:
  vector<int> postorder(Node *root) {
    if (root == nullptr) {
      return vector<int>();
    }
    vector<int> res;
    deque<Node *> q;

    Node *cur = nullptr;
    q.push_back(root);
    while (!q.empty()) {
      cur = q.back();
      q.pop_back();
      res.push_back(cur->val);
      for (auto c : cur->children) {
        q.push_back(c);
      }
    }
    reverse(res.begin(), res.end());
    return res;
  }
};