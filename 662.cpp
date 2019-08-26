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
    int widthOfBinaryTree(TreeNode *root)
    {
        vector<pair<int, int>> vec;
        return levelOrderTraversal(root, 1, 1, vec);
    }
    int levelOrderTraversal(TreeNode *root, int level, int order, vector<pair<int, int>> &vec)
    {
        if (!root)
            return 0;
        if (vec.size() < level)
            vec.push_back(make_pair(order, order));
        else
            vec[level - 1].second = order;
        int w = vec[level - 1].second - vec[level - 1].first + 1;
        int left = levelOrderTraversal(root->left, level + 1, 2 * order, vec);
        int right = levelOrderTraversal(root->right, level + 1, 2 * order + 1, vec);
        return max({w, left, right});
    }
};