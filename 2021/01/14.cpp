/*
Problem: https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/580/week-2-january-8th-january-14th/3603/
Title: Minimum Operations to Reduce X to Zero
*/
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int l = 0,
            r = 0,
            n = nums.size();
            
        int target = 0;
        for (int i = 0; i < n; ++i)
            target += nums[i];
        target -= x;
        
        if (target == 0) return n;
        if (target < 0) return -1;
        
        // cout << "Looking for the longest centralized array with sum of values = " << target << endl;
        
        int c = 0;
        int longest = -1;
        
        while (l <= r && r <= n) {
            // cout << "l:" << l << "|r:" << r << "|c: " << c << "|longest: " << longest << endl;
            
            if (c == target)
                longest = max(longest, r - l);
            
            if (c >= target)
                c -= nums[l++];
            else
                c += nums[r++];
        }
        
        // cout << "---" << endl;
        
        return (longest > -1)
            ? n - longest
            : -1;
    }
};
