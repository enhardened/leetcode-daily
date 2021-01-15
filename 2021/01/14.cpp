/*
Problem: https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/580/week-2-january-8th-january-14th/3603/
Title: Minimum Operations to Reduce X to Zero
*/
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int result = -1,
            l = 0,
            r = 0,
            n = nums.size(),
            sum = 0;
        
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
        }
        
        int sub_sum = sum - x;
        
        // cout << "Sum of nums: " << sum << endl;
        // cout << "Looking for the longest centralized array with sum of values = " << sub_sum << endl;
        
        int c = nums[0];
        
        while (l < n && r < n) {
            // cout << "l:" << l << "|r:" << r << "|c: " << c << "|res: " << result << endl;
            
            if (c == sub_sum) {
                int subarray_size = (r - l + 1);
                
                // cout << "match " << c << " with " << subarray_size << " elements" << endl;
                
                result = (result == -1) 
                    ? n - subarray_size
                    : min(result, n - subarray_size);
                
                c -= nums[l++];
            } else if (c < sub_sum) {
                c += nums[++r];
            } else { // c > sub_sum
                c -= nums[l++];
            }
        }
        
        // cout << "---" << endl;
        
        return result;
    }
};