// Problem: https://leetcode.com/problems/shortest-unsorted-continuous-subarray
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int i;
        int l = 0,
            r = n - 1;
        
        // find the longest sorted begining
        while (l < r && nums[l] <= nums[l + 1])
            ++l;
        
        // search for numbers smaller than the ones in the sorted begining
        // and adjust the left reference
        i = l;
        while (i < n && l >= 0)
            if (nums[i] < nums[l])
                --l;
            else
                ++i;
        
        // search for the longest sorted ending
        while (l < r && nums[r] >= nums[r-1])
            --r;
        
        i = r;
        while (i > l && r < n)
            if (nums[i] > nums[r])
                ++r;
            else
                --i;
        
        return l != r 
            ? r - l - 1
            : 0;
    }
};
