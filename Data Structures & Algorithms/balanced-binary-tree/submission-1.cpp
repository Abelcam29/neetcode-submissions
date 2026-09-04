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
    int depth(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0;
        }
        int left = depth(root->left);
        int right = depth(root->right);
        return 1 + max(left, right);
    }
    bool balanced(TreeNode* root)
    {
        if(root == nullptr)
        {
            return true;
        }
        int left = depth(root->left);
        int right = depth(root->right);
        if(abs(left - right) > 1)
        {
            return false;
        }
        return balanced(root->left) && balanced(root->right);
    }
    bool isBalanced(TreeNode* root) {
        bool r = balanced(root);
        return r;
    }
};
