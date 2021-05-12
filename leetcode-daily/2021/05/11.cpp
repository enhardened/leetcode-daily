// Problem: Maximum Points You Can Obtain from Cards
// URL: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/599/week-2-may-8th-may-14th/3739/
class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();        
        int sum = 0;
        
        for (int l = 0; l < k; ++l) {
            sum += nums[l];
        }
    
        if (n == k) {
            return sum;
        }
        
        int result = sum;
        
        for (int l = k - 1, r = n - 1; l > -1; --l, --r) {
            sum = sum - nums[l] + nums[r];
            result = max(result, sum);
        }
        
        return result;
    }
};