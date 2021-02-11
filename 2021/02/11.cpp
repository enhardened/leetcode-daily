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
        
        vector<int> charsInS(26);
        vector<int> charsInT(26);
        
        for (int i = 0; i < n; ++i) {
            ++charsInS[(int) s[i] - (int) 'a'];
            ++charsInT[(int) t[i] - (int) 'a'];
        }
        
        for (int i = 0; i < 26; ++i) {
            if (charsInS[i] != charsInT[i])
                return false;
        }
        
        return true;
    }
};
