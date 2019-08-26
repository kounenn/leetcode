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
    int kthSmallest(TreeNode *root, int k)
    {
        if (!treeVal.size())
            traversal(root);
        return treeVal[k - 1];
    }
    void traversal(TreeNode *root)
    {
        if (nullptr == root)
            return;
        traversal(root->left);
        treeVal.push_back(root->val);
        traversal(root->right);
        return;
    }

  private:
    vector<int> treeVal;
};