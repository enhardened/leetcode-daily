// Problem: https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/587/week-4-february-22nd-february-28th/3654/
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
    
    int cap (unsigned int num) {
        return (int) min((unsigned int) 2147483647, num);
    }
    
    int divide(int dividend, int divisor) {
        // cout << pow(2, 31) - 1 << endl;
        
        bool n1 = dividend < 0,
             n2 = divisor < 0;
        
        int result = cap(divideUnsigned(
            (unsigned int) abs(dividend), 
            (unsigned int) abs(divisor)
        ));
        
        return (n1 == n2)
            ? result
            : -result;
        
        return 0;
    }
};
