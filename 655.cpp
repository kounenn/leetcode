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
    vector<vector<string>> printTree(TreeNode *root)
    {
        const int h = height(root);
        const int rows = h;
        const int cols = pow(2, h) - 1;
        auto vec_rows = vector<string>(cols, "");
        auto res = vector<vector<string>>(rows, vec_rows);
        printSubTree(root, res, 0, 0, cols - 1);
        return res;
    }
    void printSubTree(TreeNode *root, vector<vector<string>> &res, int level, int left, int right)
    {
        if (nullptr == root)
            return;
        int mid = (left + right) / 2;
        res[level][mid] = to_string(root->val);
        printSubTree(root->left, res, level + 1, left, mid - 1);
        printSubTree(root->right, res, level + 1, mid + 1, right);
    }
    int height(TreeNode *root)
    {
        if (nullptr == root)
            return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
};