// Problem: To Lower Case
// URL: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/601/week-4-may-22nd-may-28th/3754/
class Solution {
public:
    string toLowerCase(string s) {
        int diff = 'a' - 'A';
        
        for (char &c : s)
            if (c >= 'A' && c <= 'Z')
                c += diff;
        
        return s;
    }
};
