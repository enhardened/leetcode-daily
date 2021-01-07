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
        int diff;
        
        if (k > arr[n - 1]) 
            // Form 0 to k there are only n integers on arr
            return k + n;
    
        diff = arr[n - 1] - n;
        // There are diff integers missing from 0 to arr[n-1]
        if (k > diff)
            // There are k - diff integers missing after arr[n - 1]
            return arr[n - 1] + k - diff;
        
        // Previous integer;
        int p = 0;
        
        for (int i = 0; i < n; i++) {
            // missing integers = diff - 1
            // Ex.: arr[i] = 3, arr[i-1] = 1, diff = 2, missing = 1
            diff = arr[i] - p;
            if (k < diff)
                // There are k or more missing numbers 
                // between arr[i-1] and arr[i]
                return p + k;
            
            k -= diff-1;
            p = arr[i];
        }
        
        return arr[n-1] + k;
    }
};