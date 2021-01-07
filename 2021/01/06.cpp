/*
Problem: https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/579/week-1-january-1st-january-7th/3594/
Title: Kth Missing Positive Number
Description:
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Find the kth positive integer that is missing from this array.

Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
---
Example 2:

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
*/
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        
        // Will hold the number of missing integers between two integers
        int missing;
        
        if (k > arr[n - 1]) 
            // Form 0 to k there are only n integers on arr
            return k + n;
    
        // From 0 to arr[n-1] there are only n integers on arr
        // the rest is missing
        missing = arr[n - 1] - n;
        
        if (k > missing)
            // If there were no integers missing from 0 to arr[n-1]
            // there would be k integers missing after arr[n-1]
            // Otherwise there would be `k - missing` integers missing after arr[n - 1]
            return arr[n - 1] + k - missing;
        
        // The number of missing integers between arr[i-1] and arr[i] 
        // can be calculated as `arr[i] - 1 - arr[i-1]`.
        // As there are no arr[i - 1] when i = 0
        // I created a "fake" previous to calculate missing integers from 0 to arr[0]
        int p = 0;
        
        for (int i = 0; i < n; i++) {
            // missing = arr[i] - 1 - arr[i - 1] 
            missing = arr[i] - 1 - p;
            
            if (k <= missing)
                // There are k or more missing numbers 
                // between p (arr[i-1]) and arr[i]
                return p + k;
            
            k -= missing;
            
            // p becomes arr[i-1]
            p = arr[i];
        }
        
        // This shouldn't be executed as it was already calculated on the second if
        return arr[n-1] + k;
    }
};
