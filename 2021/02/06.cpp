/*
Problem: https://leetcode.com/explore/item/3630
Title: Binary Tree Right Side View
*/
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
    void flat(TreeNode *node, int level, vector<int> *result) {
        if (!node) return; 
        
        if (result->size() > level) {
            result->at(level) = node->val;
        } else {
            result->push_back(node->val);
        }
        
        ++level;
        flat(node->left, level, result);
        flat(node->right, level, result);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        
        flat(root, 0, &result);
        
        return result;
    }
};
