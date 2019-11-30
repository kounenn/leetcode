/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
 *
 * https://leetcode.com/problems/subtree-of-another-tree/description/
 *
 * algorithms
 * Easy (42.83%)
 * Likes:    1585
 * Dislikes: 70
 * Total Accepted:    146.9K
 * Total Submissions: 341.4K
 * Testcase Example:  '[3,4,5,1,2]\n[4,1,2]'
 *
 *
 * Given two non-empty binary trees s and t, check whether tree t has exactly
 * the same structure and node values with a subtree of s. A subtree of s is a
 * tree consists of a node in s and all of this node's descendants. The tree s
 * could also be considered as a subtree of itself.
 *
 *
 * Example 1:
 *
 * Given tree s:
 *
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \
 * ⁠1   2
 *
 * Given tree t:
 *
 * ⁠  4
 * ⁠ / \
 * ⁠1   2
 *
 * Return true, because t has the same structure and node values with a subtree
 * of s.
 *
 *
 * Example 2:
 *
 * Given tree s:
 *
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \
 * ⁠1   2
 * ⁠   /
 * ⁠  0
 *
 * Given tree t:
 *
 * ⁠  4
 * ⁠ / \
 * ⁠1   2
 *
 * Return false.
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
class Solution {
  bool isSameTree(TreeNode *s, TreeNode *t) {
    if (s == t) {
      return true;
    }
    if (s == nullptr || t == nullptr) {
      return false;
    }
    return (s->val == t->val) && isSameTree(s->left, t->left) &&
           isSameTree(s->right, t->right);
  }

public:
  bool isSubtree(TreeNode *s, TreeNode *t) {
    if (s == t) {
      return true;
    }
    if (s == nullptr || t == nullptr) {
      return false;
    }
    bool ok = false;
    if (s->val == t->val) {
      ok = isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
    }
    return ok || isSubtree(s->left, t) || isSubtree(s->right, t);
  }
};
// @lc code=end
