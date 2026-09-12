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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        if(root == nullptr)
        {
            return s;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if(node == nullptr)
            {
                s.append("x,");
            }
            else
            {
                s.append(to_string(node->val)+',');
                if(node != nullptr)
                {
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0)
        {
            return nullptr;
        }
        stringstream s(data);
        string str;
        getline(s, str, ',');
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            getline(s, str, ',');
            if(str == "x")
            {
                node->left = nullptr;
            }
            else
            {
                TreeNode* nodeLeft = new TreeNode(stoi(str));
                node->left = nodeLeft;
                q.push(nodeLeft);
            }
            getline(s, str, ',');
            if(str == "x")
            {
                node->right = nullptr;
            }
            else
            {
                TreeNode* nodeRight = new TreeNode(stoi(str));
                node->right = nodeRight;
                q.push(nodeRight);
            }
        }
        return root;
    }
};
