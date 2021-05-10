// Problem: https://leetcode.com/problems/average-of-levels-in-binary-tree
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
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root)
            return {};
        
        std::vector<double> result;
        
        // Trying iterative BFS instead of recursive DFS
        std::stack<std::pair<TreeNode*, int>> stack;
        std::vector<std::pair<double, int>> data;
        
        stack.push({root, 0});
        
        while (!stack.empty()) {
            auto [node, level] = stack.top();
            stack.pop();
            
            if (data.size() == level)
                data.push_back({node->val, 1});
            else
                data[level].first += node->val,
                data[level].second++;

            if (node->left) 
                stack.push({node->left, level + 1});
            
            if (node->right) 
                stack.push({node->right, level + 1});
        }
        
        for (auto [sum, count] : data)
            result.push_back(sum / count);
        
        return result;
    }
};
