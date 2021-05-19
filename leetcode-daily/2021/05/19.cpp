// Problem: Minimum Moves to Equal Array Elements II
// URL: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/600/week-3-may-15th-may-21st/3748/
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int center = nums[nums.size() / 2];
        int result = 0;
        
        for (auto num : nums)
            result += abs(num - center);
        
        return result;
    }
};
