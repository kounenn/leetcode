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
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        unordered_map<string, int> treeMap;
        vector<TreeNode *> res;
        traversal(root, treeMap, res);
        return res;
    }

    string traversal(TreeNode *root, unordered_map<string, int> &treeMap, vector<TreeNode *> &res)
    {
        if (!root)
            return "#";
        string s = to_string(root->val) + traversal(root->left, treeMap, res) + traversal(root->right, treeMap, res);
        treeMap[s]++;
        if (treeMap[s] == 2)
            res.push_back(root);
        return s;
    }
};