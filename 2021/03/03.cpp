// Problem: https://leetcode.com/problems/missing-number/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        int expectedSum = ((1+n) * n) >> 1;
        int actualSum = 0;
        
        for (auto num : nums)
            actualSum += num;
        
        return expectedSum - actualSum;
    }
};
