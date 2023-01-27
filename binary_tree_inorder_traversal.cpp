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
    // Inorder traversal
    void inOrder(TreeNode* node, vector<int>& out) {
        if (!node)  return;
        inOrder(node->left, out);
        out.push_back(node->val);
        inOrder(node->right, out);
    }
    // Preorder traversal
    /*
    void preOrderTraversal(TreeNode* node, vector<int>& out) {
        if (!node) return;
        if (node->left) {
            preOrderTraversal(node->left, out);  
        }
        if (node->right) {
            preOrderTraversal(node->right, out);
        }
        out.push_back(node->val);
    }
    */
    //
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int> res;
       inOrder(root, res);
       return res; 
    }
};
