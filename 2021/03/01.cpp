// Problem: https://leetcode.com/problems/distribute-candies/
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        int limit = n / 2;
        int type_count = 0;
        
        unordered_set<int> seen_types;
        
        for (int i = 0; i < n; ++i) {
            if (seen_types.count(candyType[i]) == 0) {
                ++type_count;
                seen_types.insert(candyType[i]);
            }
        }
        
        return min(type_count, limit);
    }
};
