/*
Problem: https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/580/week-2-january-8th-january-14th/3600/
Title: Merge Sorted Array
Description:

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

The number of elements initialized in nums1 and nums2 are m and n respectively. 
You may assume that nums1 has enough space (size that is equal to m + n) to hold additional elements from nums2. 

---
Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
---
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
---

Constraints:

0 <= n, m <= 200
1 <= n + m <= 200
nums1.length == m + n
nums2.length == n
-109 <= nums1[i], nums2[i] <= 109
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /*
        Only the first m values from nums1 are going to be kept (tested on Custom Testcase)
        The rest is ignored
        */
        // nums1[i] <= nums1[i+1]
        // nums2[i] <= nums2[i+1]
        
        int i = n + m - 1,
            i1 = m - 1,
            i2 = n - 1;
        
        while (i2 > -1) {
            nums1[i--] = (i1 > -1 && nums1[i1] > nums2[i2]) 
                ? nums1[i1--] 
                : nums2[i2--];
        } 
    }
};
