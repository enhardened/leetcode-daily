// Problem: Non-decreasing Array
// URL: https://leetcode.com/explore/featured/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3731/
class Solution {
public:
    bool checkPossibility(vector<int>& nums) 
    {
        int n = nums.size();
        
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] > nums[i+1])
            {
                // try to remove any element
                return isNonDecreasing(nums, i) || isNonDecreasing(nums, i+1);
            }
        }
        
        // Original vector is non decreasing
        return true;
    }
    
    bool isNonDecreasing(vector<int>& nums, int skipIndex)
    {
        int n = nums.size();
            
        if (skipIndex == n - 1)
            n--;
        
        for (int i = 0; i < n - 1; i++) 
        {
            if (i == skipIndex)
                continue;
            
            // Skip removed element
            int next = (i + 1 == skipIndex)
                ? i+2
                : i+1;
            
            if (nums[i] > nums[next])
                return false;
        }
        
        return true;
    }
};
