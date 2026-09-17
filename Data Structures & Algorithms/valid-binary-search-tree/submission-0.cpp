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
    bool validBST(TreeNode* root, long long long_max, long long long_min)
    {
        if(root == nullptr)
        {
            return true;
        }
        if(root->val <= long_min || root->val >= long_max)
        {
            return false;
        }
        return validBST(root->left, root->val, long_min) && validBST(root->right, long_max, root->val);
    }
    bool isValidBST(TreeNode* root) {
        bool n = validBST(root, LLONG_MAX, LLONG_MIN);
        return n;
    }
};
