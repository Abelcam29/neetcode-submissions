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
    int n = 0;
public:
    int diameter(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0;
        }
        int left = diameter(root->left);
        int right = diameter(root->right);
        int dia = left + right;
        n = max(n, dia);
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        n = 0;
        diameter(root);
        return n;
    }
};
