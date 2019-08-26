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
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (!s && t)
        {
            return false;
        }
        return isSameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    bool isSameTree(TreeNode *s, TreeNode *t)
    {
        if (!s && !t)
        {
            return true;
        }
        if (s && t && s->val == t->val)
        {
            return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
        }
        return false;
    }
};