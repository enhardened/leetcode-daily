// https://leetcode.com/explore/featured/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3812/
// Title: Find Peak Element
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n;
        int c, next, prev;
        
        while (l < r) {
            c = (l + r) / 2;
            next = c + 1;
            prev = c - 1;
            
            if (next < n && nums[next] > nums[c]) {
                l = next;
            } else if (prev > -1 && nums[prev] > nums[c]) {
                r = c;
            } else {
                break;
            }
        }
        
        return c;
    }
};