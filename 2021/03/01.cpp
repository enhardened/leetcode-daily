// Problem: https://leetcode.com/problems/distribute-candies/
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        int limit = n / 2;
        
        unordered_set<int> seen_types(candyType.begin(), candyType.end());
        
        return min(limit, (int) seen_types.size());
    }
};
