/*
Problem: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
Title: Minimum Remove to Make Valid Parentheses
*/
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length(),
            openings = 0,
            closings = 0;
        
        string result = "";
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == ')')
                ++closings;
        }
        
        for (int i = 0; i < n; ++i) {
            switch (s[i]) {
                case '(':
                    if (openings < closings) {
                        ++openings;
                        result += s[i];
                    }
                    break;
                case ')':
                    if (openings > 0) {
                        --openings;
                        result += s[i];
                    }
                    --closings;
                    break;
                default:
                    result += s[i];
            }
        }
        
        return result;
    }
};
