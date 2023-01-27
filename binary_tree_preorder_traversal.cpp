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
    // RECURSIVE
    /*
    void traverse(TreeNode* node, vector<int>& v) {
        if (!node) return;
        v.push_back(node->val);
        traverse(node->left, v);
        traverse(node->right, v);
    }
    */
    // ITERATIVE : raw with two queues for each recursive call
    /*
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res; 
        //traverse(root, res);
        stack<TreeNode*> ql;
        stack<TreeNode*> qr;
        ql.push(root);
        while (ql.size() || qr.size()) {
            if (ql.size()) {
                auto node = ql.top();
                ql.pop();
                res.push_back(node->val);
                if (node->left) ql.push(node->left);
                if (node->right) qr.push(node->right);
            }
            else if (qr.size()) {
                auto node = qr.top();
                qr.pop();
                res.push_back(node->val);
                if (node->left) ql.push(node->left);
                if (node->right) qr.push(node->right);
            }
        }
        return res;
    }
    */
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res; 
        stack<TreeNode*> nodesToTreat;
        nodesToTreat.push(root);
        while (nodesToTreat.size()) {
            auto node = nodesToTreat.top();
            nodesToTreat.pop();
            
            res.push_back(node->val);
                        
            //trick: opposite order compared to recursive
            //       => right then left
            if (node->right) nodesToTreat.push(node->right);
            if (node->left) nodesToTreat.push(node->left);
        }
        return res;
    }
};
