/*
Problem: https://leetcode.com/explore/item/3649
Title: Longest Word in Dictionary through Deleting
*/
class Solution {
public:
    bool isSubsequence(string &s, string &word) {
        int n = s.length(),
            m = word.length(),
            i = 0,
            j = 0;
        
        while (i < n && j < m) {
            if (s[i] == word[j]) 
                ++j;
            
            ++i;
        }

        return j == m;
    }
    
    string findLongestWord(string s, vector<string>& d) {
        string longest = "";
        
        for (int i = 0; i < d.size(); ++i) {
            // Ignore words smaller than the current longest
            if (longest.length() > d[i].length())
                continue;
            
            // Ignore words that are not a subsequence of s
            if (!isSubsequence(s, d[i]))
                continue;
            
            if (longest.length() < d[i].length() || longest > d[i])
                longest = d[i];
        }
        
        return longest;
    }
};
