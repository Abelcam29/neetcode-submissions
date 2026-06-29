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
private:
    vector<int> res2;
public:
    vector<int> inorder(TreeNode* root)
    {
        if(root == nullptr)
        {
            return {};
        }
        inorder(root->left);
        res2.push_back(root->val);
        inorder(root->right);
        return res2;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res = inorder(root);
        return res;
    }
};