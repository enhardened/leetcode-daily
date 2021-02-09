/*
Problem: https://leetcode.com/explore/item/3631
Title: Shortest Distance to a Character
*/
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        
        vector<int> result(n, INT_MAX);
        
        int last = -n;
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == c)
                last = i;
            
            result[i] = i - last;
        }
        
        for (int i = last; i >= 0; --i) {
            if (s[i] == c)
                last = i;
            
            result[i] = min(result[i], last - i);
        }
        
        return result;
    }
};
