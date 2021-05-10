// Problem: https://leetcode.com/problems/divide-two-integers
class Solution {
public:    
    unsigned int divideUnsigned(unsigned int dividend, unsigned int divisor) {
        unsigned int result = 0;
        
        if (divisor == 1)
            return dividend;
        
        while (dividend >= divisor) {
            dividend -= divisor;
            ++result;
        }
        
        return result;
    }
    
    int divide(int dividend, int divisor) {
        
        unsigned int result = divideUnsigned(
            (unsigned int) abs(dividend), 
            (unsigned int) abs(divisor)
        );
        
        return ((dividend < 0) == (divisor < 0))
            ? (int) min((unsigned int) 2147483647, result)
            : (int) -min((unsigned int) 2147483648, result);
    }
};
