/*
Problem: https://leetcode.com/explore/item/3631
Title: Shortest Distance to a Character
*/
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        
        vector<int> result(n, INT_MAX);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s[j] == c)
                    result[i] = min(result[i], abs(i-j));
            }
        }
        
        return result;
    }
};