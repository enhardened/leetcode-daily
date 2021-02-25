// Problem: https://leetcode.com/problems/score-of-parentheses
class Solution {
public:
    int scoreOfParentheses(string S) {
        int result = 0;
        int unit = 1;
        
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] == '(')
                unit = unit << 1; // unit *= 2
            else { // S[i] == ')'
                unit = unit >> 1; // unit /= 2
            
                if (S[i-1] == '(')
                    result += unit;
            }
            
        }
        
        return result;
    }
};
