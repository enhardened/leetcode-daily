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
    void flat(TreeNode *node, int level, int *maxRight, vector<int> *result) {
        if (!node) return; 
        
        if (level == *maxRight) {
            result->push_back(node->val);
            (*maxRight)++;
        }
        
        ++level;
        flat(node->right, level, maxRight, result);
        flat(node->left, level, maxRight, result);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        
        int maxRight = 0;
        
        flat(root, 0, &maxRight, &result);
        
        return result;
    }
};
