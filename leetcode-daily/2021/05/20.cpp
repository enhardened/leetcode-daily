// Problem: Binary Tree Level Order Traversal
// URL: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/600/week-3-may-15th-may-21st/3749/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        deque<TreeNode*> q;
        
        TreeNode *currentNode = nullptr;
        int currentLevel;
        
        if (root)
            q.push_back(root);
        
        while (q.size() > 0) {
            result.push_back(vector<int>());
            currentLevel = result.size() - 1;
            
            for (int i = 0, n = q.size(); i < n; ++i) {
                currentNode = q.front();
                q.pop_front();
                
                result[currentLevel].push_back(currentNode->val);
                
                if (currentNode->left)
                    q.push_back(currentNode->left);
                
                if (currentNode->right)
                    q.push_back(currentNode->right);
            }
        }
        
        return result;
    }
};
