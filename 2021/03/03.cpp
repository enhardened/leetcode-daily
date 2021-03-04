// Problem: https://leetcode.com/problems/missing-number/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<bool> helper(n+1, false);
        
        for (auto num : nums)
            helper[num] = true;
        
        for (int i = 0; i <= n; ++i) 
            if (!helper[i])
                return i;
        
        throw invalid_argument("There are no missing numbers.");
    }
};
