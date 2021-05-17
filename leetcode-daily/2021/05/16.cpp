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
    
    int minCameraCover(TreeNode* root) {
        dfs(root, nullptr);
        return result;
    }

    // return remaining coverage
    // 1 if node is has a cam
    // 0 if a child has a cam
    // -1 if neither the node or both its children doesn't have a cam
    int dfs(TreeNode *node, TreeNode *parent) {
        if (!node)
            return 0;
        
        int lrd = dfs(node->left, node);
        int rrd = dfs(node->right, node);
        
        bool isCovered = lrd == 1 || rrd == 1;
        bool hasUncoveredChild = lrd == -1 || rrd == -1;
        
        // ---
        if (hasUncoveredChild) {
            result++;
            return 1;
        } else if (isCovered) {
            return 0;
        } else {
            if (parent)
                return -1;
            
            result++;
        }
        // ---
        
        return 0;
    }
};
