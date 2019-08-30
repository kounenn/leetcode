#include <deque>
#include <tuple>
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
  vector<vector<int>> levelOrder(Node *root) {
    vector<vector<int>> res;
    if (root == nullptr) {
      return res;
    }
    int level = 0;
    deque<tuple<int, Node *>> q;
    auto cur = root;
    q.emplace_back(make_tuple(level, cur));
    while (!q.empty()) {
      tie(level, cur) = q.front();
      q.pop_front();
      if (level >= res.size()) {
        res.emplace_back();
      }
      res.back().push_back(cur->val);
      for (auto c : cur->children) {
        q.emplace_back(make_tuple(level + 1, c));
      }
    }
    return res;
  }
};