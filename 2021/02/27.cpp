// Problem: https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/587/week-4-february-22nd-february-28th/3654/
class Solution {
public:
    int divide(int dividend, int divisor) {
        int result = 0;
        bool n1 = dividend < 0,
             n2 = divisor < 0;
        
        dividend = abs(dividend);
        divisor = abs(divisor);
        
        while (dividend >= divisor) {
            dividend -= divisor;
            ++result;
        }
        
        return (n1 == n2)
            ? result
            : -result;
    }
};
