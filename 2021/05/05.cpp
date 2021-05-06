// Problem: Jump Game II
// URL: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3732/
class Solution {
public:
    int jump(vector<int>& nums) {
        int maxReach = 0,
            minJumps = 0,
            n = nums.size() - 1,
            i = 0;
        
        int nextMaxReach = maxReach;
        
        while (maxReach < n) {
        
            while (i <= maxReach && nextMaxReach < n) {
                nextMaxReach = max(nextMaxReach, i + nums[i]);
                i++;
            }
            
            maxReach = nextMaxReach;
            minJumps++;
        }
        
        return minJumps;
    }
};
