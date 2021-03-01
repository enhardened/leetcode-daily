// Problem: https://leetcode.com/problems/distribute-candies/
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        int limit = n / 2;
        int type_count = 1;
        
        sort(candyType.begin(), candyType.end());
        
        for (int i = 1; i < n; ++i)
            if (candyType[i] > candyType[i-1])
                ++type_count;
        
        return min(limit, type_count);
    }
};
