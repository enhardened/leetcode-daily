// Problem: https://leetcode.com/explore/item/3666
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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1)
            return new TreeNode(v, root, nullptr);
        
        queue<tuple<TreeNode*, int>, list<tuple<TreeNode*, int>>> q; // {node, depth}
        q.push({root, 1});
        
        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();
            
            if (depth == d - 1) {
                node->left = new TreeNode(v, node->left, nullptr);
                node->right = new TreeNode(v, nullptr, node->right);
            } else {
                if (node->left) q.push({node->left, depth + 1});
                if (node->right) q.push({node->right, depth + 1});
            }
        }
        
        return root;
    }
};