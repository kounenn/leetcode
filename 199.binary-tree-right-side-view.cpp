/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 *
 * https://leetcode.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (50.37%)
 * Likes:    1427
 * Dislikes: 75
 * Total Accepted:    211.1K
 * Total Submissions: 418.1K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * Given a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
 *
 * Example:
 *
 *
 * Input: [1,2,3,null,5,null,4]
 * Output: [1, 3, 4]
 * Explanation:
 *
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
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

#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    vector<int> r;
    if (root == nullptr) {
      return r;
    }
    queue<TreeNode *> q;
    q.push(root);
    q.push(nullptr); //标志一层的结束
    int right;
    for (; !q.empty();) {
      auto cur = q.front();
      q.pop();
      if (cur == nullptr) { // 一层遍历完成
        r.push_back(right); // 记录该层最右侧的元素
        if (!q.empty()) {   // 若还有下一层
          q.push(nullptr);  // 增加下一层的结束标志
        }
        continue;
      }
      right = cur->val;
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
