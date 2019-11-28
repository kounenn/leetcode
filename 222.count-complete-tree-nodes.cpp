/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
 *
 * https://leetcode.com/problems/count-complete-tree-nodes/description/
 *
 * algorithms
 * Medium (38.64%)
 * Likes:    1393
 * Dislikes: 159
 * Total Accepted:    161.6K
 * Total Submissions: 415K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * Given a complete binary tree, count the number of nodes.
 *
 * Note:
 *
 * Definition of a complete binary tree from Wikipedia:
 * In a complete binary tree every level, except possibly the last, is
 * completely filled, and all nodes in the last level are as far left as
 * possible. It can have between 1 and 2^h nodes inclusive at the last level
 * h.
 *
 * Example:
 *
 *
 * Input:
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠/ \  /
 * 4  5 6
 *
 * Output: 6
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

#include <queue>

using namespace std;

class Solution {
  int num(TreeNode *root) {
    int lh = 1, rh = 1;
    for (auto cur = root; cur->left != nullptr; cur = cur->left) {
      lh++;
    }
    for (auto cur = root; cur->right != nullptr; cur = cur->right) {
      rh++;
    }
    if (lh == rh) {
      return pow(2, lh) - 1;
    }
    return -1;
  }

public:
  int countNodes(TreeNode *root) {
    int r = 0;
    if (root == nullptr) {
      return r;
    }
    queue<TreeNode *> q;
    q.push(root);
    for (TreeNode *cur = nullptr; !q.empty();) {
      cur = q.front();
      q.pop();
      int n = num(cur);
      if (n != -1) {
        r += n;
        continue;
      }
      r += 1;
      if (cur->left) {
        q.push(cur->left);
      }
      if (cur->right) {
        q.push(cur->right);
      }
    }
    return r;
  }
};
// @lc code=end
