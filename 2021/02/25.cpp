// Problem: https://leetcode.com/problems/shortest-unsorted-continuous-subarray
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int l = 0,
            r = nums.size() - 1;
        
        // find the longest sorted begining
        while (l < r && nums[l] <= nums[l + 1])
            ++l;
        
        // search for the longest sorted ending
        while (l < r && nums[r] >= nums[r-1])
            --r;
        
        auto [minNum, maxNum] = minmax_element(nums.begin() + l, nums.begin() + r + 1);
        
        auto lb = upper_bound(nums.begin(), nums.begin() + l, *minNum);
        auto rb = lower_bound(nums.begin() + r, nums.end(), *maxNum);
        
        return distance(lb, rb);
    }
};
