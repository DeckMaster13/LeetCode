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
    bool areChildrenSymmetric(TreeNode* left, TreeNode* right) {
        if (!left || !right) return left == right;// good trick
        return left->val == right->val
            && areChildrenSymmetric(left->left, right->right)
            && areChildrenSymmetric(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return areChildrenSymmetric(root->left, root->right);
    }
};
