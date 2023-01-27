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
    void recSearch(TreeNode* node, const string& path, vector<string>& res) {
        if (!node) return;
        string updatedPath = path + "->" + to_string(node->val);
        recSearch(node->left, updatedPath, res);
        recSearch(node->right, updatedPath, res);
        if (!node->left && !node->right) res.push_back(updatedPath);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) return res;
        if (!root->left && !root->right) return vector<string>{to_string(root->val)}; 
        string path = to_string(root->val);
        recSearch(root->left, path, res);
        recSearch(root->right, path, res);
        return res;
    }
};
