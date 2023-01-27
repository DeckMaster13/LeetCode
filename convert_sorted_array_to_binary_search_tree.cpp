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
    TreeNode* genSubTree(const vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        
        auto mid = (left+right)/2;
        auto node = new TreeNode(nums[mid]);
        node->left = genSubTree(nums, left, mid-1);
        node->right = genSubTree(nums, mid+1, right);
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        return genSubTree(nums, 0, nums.size() - 1);
    }
};
