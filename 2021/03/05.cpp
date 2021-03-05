// Problem: https://leetcode.com/problems/average-of-levels-in-binary-tree
class Solution {
public:
    vector<pair<long int, int>> data;
    
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        // To find the average value of each level
        // I need to know the sum of all nodes on each level
        // and the number of nodes on each level
        
        // One possibility is to traverse the tree 
        // while creating a map of level to [sum, count] 
        // then iterate over the map dividing sum by count 
        // and appending the division result to the result array
        // Time complexity would be O(n), n being the number of nodes
        // Space complecity would be O(m), m being the lenght of the deepest level of the tree 
        
        // Is there a more efficient way to calculate the average?
        // O(n) time seens to be the minium possible since it will need to know every node value
        // linear space would be the minium possible to store each level's average before returning
        // But is it possible to reduce the angular coefficient of the space complexity?
        // - I am unable find a more efficient solution at this time
        
        traverse(root, 0);
        
        for (auto &row : data)
            result.push_back((double) row.first / row.second);
        
        return result;
    }
    
    void traverse(TreeNode *node, int level) {
        if (!node)
            return;
        
        if (data.size() == level)
            data.push_back(make_pair(node->val, 1));
        else
            data[level].first += node->val,
            ++data[level].second;
        
        traverse(node->left, level + 1);
        traverse(node->right, level + 1);
    }
};
