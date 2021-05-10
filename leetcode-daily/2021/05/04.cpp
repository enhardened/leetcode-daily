// Problem: Non-decreasing Array
// URL: https://leetcode.com/explore/featured/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3731/
class Solution {
public:
    bool checkPossibility(vector<int>& nums) 
    {
        int n = nums.size();
        bool hasRemovedAnyElement = false;
        
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] > nums[i+1])
            {
                if (hasRemovedAnyElement)
                    return false;
                
                if (i == 0 || nums[i-1] <= nums[i+1])
                {
                    hasRemovedAnyElement = true;
                    continue;
                }
                
                if (i == n - 2 || nums[i] <= nums[i+2])
                {
                    hasRemovedAnyElement = true;
                    i++;
                    continue;
                }
                
                return false;
            }
        }
        
        // Original vector is non decreasing
        return true;
    }
};
