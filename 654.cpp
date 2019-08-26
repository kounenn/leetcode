/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
  TreeNode *constructMaximumBinaryTree(vector<int> &nums)
  {
    if (nums.begin() == nums.end())
    {
      return nullptr;
    }
    auto n = max_element(nums.begin(), nums.end());
    auto root = new TreeNode(*n);
    auto left = vector<int>(nums.begin(), n);
    auto right = vector<int>(n + 1, nums.end());
    root->left = constructMaximumBinaryTree(left);
    root->right = constructMaximumBinaryTree(right);
    return root;
  }
};