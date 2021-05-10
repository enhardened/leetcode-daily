// Problem: https://leetcode.com/problems/distribute-candies/
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        bitset<200001> types(0);
        
        for (int i = 0; i < n; ++i)
            types.set(100000 + candyType[i]);
        
        return min(n / 2, (int) types.count());
    }
};
