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
// Jump
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int c = 0; // current integer being checked
        int i = 0; // current arr index
        int j = 0; // variable to calculate the "jump" to the next missing integer
        
        while (k > 0) {
            c++;
                
            if (i < arr.size() && arr[i] == c)
                i++;
            else {
                j = i < arr.size()
                    ? min(arr[i] - c, k)
                    : k;
                k -= j;
                c += j-1;
            }
        }
        
        return c;
    }
};