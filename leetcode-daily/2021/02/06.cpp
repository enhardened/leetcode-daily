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
    vector<int> result;
    
    void dfs(TreeNode *node, int level, int *maxRight) {
        if (!node) return; 
        
        if (level == *maxRight) {
            result.push_back(node->val);
            (*maxRight)++;
        }
        
        ++level;
        dfs(node->right, level, maxRight);
        dfs(node->left, level, maxRight);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        int maxRight = 0;
        
        dfs(root, 0, &maxRight);
        
        return result;
    }
};
