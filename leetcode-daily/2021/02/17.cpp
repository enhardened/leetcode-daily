/*
Problem: https://leetcode.com/explore/item/3643
Title: Container With Most Water
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0,
            r = height.size() - 1;
        
        int result = 0;
        
        while (l < r) {
            result = max(
                result, 
                min(height[l], height[r]) * (r - l)
            );

            if (height[l] < height[r]) {
                // seek the next bar greater than height[l] from left to right
                ++l;
            } else {
                // seek the next bar greater than height[r] from right to left
                --r;
            }
        }
        
        return result;
    }
};
