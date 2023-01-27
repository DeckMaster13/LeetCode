/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

using MapNode = vector<TreeNode*>;

class Solution {
public:
    void mapNode(TreeNode* root, TreeNode* node, MapNode& map, bool& found) {
        if (root == nullptr) { cerr << "nullptr"; return; }
        map.push_back(root);
        cerr << root->val;
        if (root == node) { found = true; return; }
        
        MapNode leftMap = map;        
        mapNode(root->left, node, leftMap, found);
        if (found) { map = leftMap; return; }

        MapNode rightMap = map;
        mapNode(root->right, node, rightMap, found);
        if (found) { map = rightMap; return; }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        MapNode pMap{};
        MapNode qMap{};
        
        bool found = false;
        mapNode(root, p, pMap, found); 
        
        found = false;
        mapNode(root, q, qMap, found);
                
        for (auto pMapIt = pMap.rbegin(); pMapIt != pMap.rend(); pMapIt++) {
            for (auto qMapIt = qMap.rbegin(); qMapIt != qMap.rend(); qMapIt++) {
                if (*qMapIt == *pMapIt) return *pMapIt;
            }
        }
        return nullptr;
    }
};
