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
    TreeNode *addOneRow(TreeNode *root, int v, int d)
    {
        if (d == 1)
        {
            TreeNode *left = root;
            root = new TreeNode(v);
            root->left = left;
        }
        else
        {
            levelOrderTraversal(root, 1, v, d);
        }
        return root;
    }

    void levelOrderTraversal(TreeNode *root, int level, int v, int d)
    {
        if (!root)
        {
            return;
        }
        if (level == d - 1)
        {
            TreeNode *left = root->left;
            TreeNode *right = root->right;
            root->left = new TreeNode(v);
            root->right = new TreeNode(v);
            root->left->left = left;
            root->right->right = right;
            return;
        }
        levelOrderTraversal(root->left, level + 1, v, d);
        levelOrderTraversal(root->right, level + 1, v, d);
    }
};