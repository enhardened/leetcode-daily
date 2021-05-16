// Problem: Valid Number
// URL: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/600/week-3-may-15th-may-21st/3744/
class Solution {
public:
    bool isNumber(string s) {
        int i = 0,
            n = s.length();
        
        bool is_signed = s[i] == '+' || s[i] == '-';
        
        if (is_signed && ++i == n)
            return false;
        
        // ignore digits
        while (i < n && s[i] >= '0' && s[i] <= '9') 
            ++i;
        
        bool is_decimal = i < n && s[i] == '.';
        
        if (is_decimal)
            ++i;
        
        // ignore digits
        while (i < n && s[i] >= '0' && s[i] <= '9') 
            ++i;
        
        if (i == is_signed + is_decimal)
            return false;
        
        
        bool is_e_notation = s[i] == 'e' || s[i] == 'E';
        
        if (is_e_notation) {
            if (++i == n) 
                return false;
            
            if ((s[i] == '+' || s[i] == '-') && ++i == n)
                return false;
            
            // search for non-digits
            for (; i < n; ++i)
                if (s[i] < '0' || s[i] > '9')
                    return false;
        }
        
        return i == n;
    }
};