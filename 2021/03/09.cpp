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
        
        queue<TreeNode*, list<TreeNode*>> q;
        q.push(root);
        
        int depth = 1;
        
        while (!q.empty()) {
            int depthLength = q.size();
            
            for (int i = 0; i < depthLength; ++i) {
                auto node = q.front();
                q.pop();

                if (depth == d - 1) {
                    node->left = new TreeNode(v, node->left, nullptr);
                    node->right = new TreeNode(v, nullptr, node->right);
                } else {
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
            }
            
            ++depth;
        }
        
        return root;
    }
};
