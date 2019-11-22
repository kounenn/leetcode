/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (59.40%)
 * Likes:    2147
 * Dislikes: 94
 * Total Accepted:    569.6K
 * Total Submissions: 957.6K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * Example:
 *
 *
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 *
 * Output: [1,3,2]
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 *
 */

#include <stack>
#include <vector>
using namespace std;

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


class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> r;
    stack<TreeNode *> st;
    auto cur = root;
    while (cur != nullptr || !st.empty()) {
      if (cur != nullptr) {
        st.push(cur);
        cur = cur->left;
        continue;
      }
      cur = st.top();
      st.pop();
      r.push_back(cur->val);
      cur = cur->right;
    }
    return r;
  }
};
// @lc code=end
