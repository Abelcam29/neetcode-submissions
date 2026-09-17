/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> res;
    void levelO(TreeNode* root, int level)
    {
        if(root == nullptr)
        {
            return;
        }
        if(level >= res.size())
        {
            res.push_back({});
        }
        res[level].push_back(root->val);
        levelO(root->left, level + 1);
        levelO(root->right, level + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        res.clear();
        levelO(root, 0);
        return res;
    }
};
