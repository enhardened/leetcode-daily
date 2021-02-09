/*
Problem: https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/585/week-2-february-8th-february-14th/3634/
Title: Convert BST to Greater Tree
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
    void traverse(TreeNode* node, int *sum) {
        if (!node) return;
        
        traverse(node->right, sum);
        
        (*sum) += node->val;
        node->val = *sum;
        
        traverse(node->left, sum);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        traverse(root, &sum);
        return root;
    }
};
