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
    unordered_map<int, int> in_map;

    TreeNode* build(const vector<int>& preorder, int pre_start, int pre_end, const vector<int>& inorder, int in_start, int in_end) {
        if (pre_start > pre_end || in_start > in_end) {
            return nullptr;
        }

        int root_val = preorder[pre_start];
        TreeNode* root = new TreeNode(root_val);

        int root_idx = in_map[root_val];
        int num_left = root_idx - in_start;
        root->left = build(preorder, pre_start + 1, pre_start + num_left,
                           inorder, in_start, root_idx - 1);

        root->right = build(preorder, pre_start + num_left + 1, pre_end,
                            inorder, root_idx + 1, in_end);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        in_map.clear();
        for (int i = 0; i < inorder.size(); ++i) {
            in_map[inorder[i]] = i;
        }

        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};
