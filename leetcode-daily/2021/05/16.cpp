// Problem: Binary Tree Cameras
// URL: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/600/week-3-may-15th-may-21st/3745/
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
    int result = 0;
    
    unordered_set<TreeNode*> coveredNodes;
    
    int minCameraCover(TreeNode* root) {
        dfs(root, nullptr);
        
        return result;
    }
    
    bool isCovered(TreeNode *node) {
        return !node || coveredNodes.count(node);
    }
    
    void setCovered(TreeNode *node) {
        if (node)
            coveredNodes.insert(node);
    }
    
    void dfs(TreeNode *node, TreeNode *parent) {
        if (!node)
            return;
        
        dfs(node->left, node);
        dfs(node->right, node);
        
        // ---
        if (!isCovered(node->right) || !isCovered(node->left) || (!isCovered(node) && !parent)) {
            result++;
            setCovered(node);
            setCovered(parent);
            // children won't be visited again
        }
        // ---
    }
};
