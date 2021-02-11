/*
Problem: https://leetcode.com/explore/item/3636
Title: Valid Anagram
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        
        if (n != t.length())
            return false;
        
        unordered_set<int> chars;
        unordered_map<int, int> charsInS;
        unordered_map<int, int> charsInT;
        
        for (int i = 0; i < n; ++i) {
            chars.insert((int) s[i]);
            chars.insert((int) t[i]);
            
            ++charsInS[(int) s[i]];
            ++charsInT[(int) t[i]];
        }
        
        for (auto it = chars.begin(); it != chars.end(); ++it) {
            if (charsInS[*it] != charsInT[*it])
                return false;
        }
        
        return true;
    }
};
