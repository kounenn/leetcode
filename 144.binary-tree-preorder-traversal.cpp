/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (53.12%)
 * Likes:    1029
 * Dislikes: 46
 * Total Accepted:    399.1K
 * Total Submissions: 750.6K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
 *
 * Example:
 *
 *
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 *
 * Output: [1,2,3]
 *
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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

#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> preorderTraversal(TreeNode *root) {
    stack<TreeNode *> st;
    vector<int> r;
    auto cur = root;
    while (cur != nullptr || !st.empty()) {
      if (cur == nullptr) {
        cur = st.top();
        st.pop();
      }
      r.push_back(cur->val);
      if (cur->right != nullptr) {
        st.push(cur->right);
      }
      cur = cur->left;
    }
    return r;
  }
};
// @lc code=end
