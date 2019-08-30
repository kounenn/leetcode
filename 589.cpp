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
  vector<int> preorder(Node *root) {
    vector<int> res;
    if (root == nullptr) {
      return res;
    }

    deque<Node *> q;
    auto cur = root;
    q.push_back(cur);

    while (!q.empty()) {
      cur = q.front();
      q.pop_front();
      res.push_back(cur->val);
      for (auto it = cur->children.rbegin(); it != cur->children.rend(); it++) {
        q.push_front(*it);
      }
    }
    return res;
  }
};