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
    int minCameraCover(TreeNode* root) {
        int result = 0;
        
        return dfs(root, nullptr, result) == -1
            ? result + 1
            : result;
    }

    // return remaining coverage
    // 1 if node is has a cam
    // 0 if a child has a cam
    // -1 if neither the node or both its children doesn't have a cam
    int dfs(TreeNode *node, TreeNode *parent, int &result) {
        if (!node)
            return 0;
        
        int l = dfs(node->left, node, result);
        int r = dfs(node->right, node, result);
        
        // Any child not covered
        if (l == -1 || r == -1) {
            result++;
            return 1;
        } 
        
        // Covered by any child
        if (l == 1 || r == 1)
            return 0;
        
        return -1;
    }
};
