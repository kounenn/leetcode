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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        if (root == nullptr)
            return res;
        queue<TreeNode *> q;
        auto current = root;
        q.push(current);
        q.push(nullptr);
        int view = 0;
        while (!q.empty())
        {
            current = q.front();
            q.pop();
            if (current == nullptr)
            {
                res.push_back(view);
                if (!q.empty())
                    q.push(nullptr);
            }
            else
            {
                view = current->val;
                if (current->left)
                    q.push(current->left);
                if (current->right)
                    q.push(current->right);
            }
        }
        return res;
    }
};