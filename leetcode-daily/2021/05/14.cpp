// Problem: Flatten Binary Tree to Linked List
// URL: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/599/week-2-may-8th-may-14th/3742/
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
    void flatten(TreeNode* root) {
        TreeNode *curr = root,
                 *tmp = nullptr;
        
        while (curr) {
            if (curr->left) {
                tmp = curr->left;
                
                while (tmp->right)
                    tmp = tmp->right;
                
                tmp->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            
            curr = curr->right;
        }
    }
};