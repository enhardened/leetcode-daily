/*
Problem: https://leetcode.com/problems/number-of-1-bits/
Title: 191. Number of 1 Bits
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int answer = 0;
        
        for (int i = 31; i >= 0; --i) {
            long int power = pow(2, i);
            if (power <= n) {
                ++answer;
                n -= power;
            }
        }
        
        return answer;
    }
};