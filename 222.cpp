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
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        TreeNode *left = root, *right = root;
        int lh, rh;
        for (lh = 0; left; ++lh)
            left = left->left;
        for (rh = 0; right; ++rh)
            right = right->right;
        if (lh == rh)
            return pow(2, lh) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};