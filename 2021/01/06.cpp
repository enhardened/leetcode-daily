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
        
        // arr[i-1] wouldn't exist for i = 0
        // so, this situations is being handled outside of the for loop
        // but the logic is the same
        if (k < arr[0]) 
            return k;
        
        k -= arr[0] - 1;
        
        for (int i = 1; i < n; i++) {
            // missing integers = diff - 1
            // Ex.: arr[i] = 3, arr[i-1] = 1, diff = 2, missing = 1
            diff = arr[i] - arr[i-1];
            if (k < diff)
                // There are k or more missing numbers 
                // between arr[i-1] and arr[i]
                return arr[i-1] + k;
            
            k -= diff-1;
        }
        
        return arr[n-1] + k;
    }
};