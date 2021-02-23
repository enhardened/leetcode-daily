/*
Problem: https://leetcode.com/explore/item/3649
Title: Longest Word in Dictionary through Deleting
*/
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string longest = "";
        bool isSubsequence;
        
        for (int i = 0; i < d.size(); ++i) {
            // Ignore words smaller than the current longest
            if (longest.length() > d[i].length())
                continue;
            
            isSubsequence = false;
            string::iterator it = d[i].begin();
                        
            for (char c : s) {
                if (*it == c) {
                    ++it;   
                    
                    if (it == d[i].end()) {
                        isSubsequence = true;
                        break;
                    }
                }
            }
            
            // Ignore words that are not a subsequence of s
            if (!isSubsequence)
                continue;
            
            if (longest.length() < d[i].length() || longest > d[i])
                longest = d[i];
        }
        
        return longest;
    }
};
