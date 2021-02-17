class Solution {
public:
    int calculateArea(vector<int> *height, int left, int right) {
        return min((*height)[left], (*height)[right]) * (right - left);
    }
    
    int maxArea(vector<int>& height) {
        int l = 0,
            r = height.size() - 1;
        
        int result = 0;
        
        while (l < r) {
            result = max(result, calculateArea(&height, l, r));

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