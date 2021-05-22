// Problem: Find and Replace Pattern
// URL: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/600/week-3-may-15th-may-21st/3750/
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<char, char> w2p;
        unordered_map<char, char> p2w;
        vector<string> matches;
        
        int n = pattern.length();
        
        w2p.reserve(26);
        p2w.reserve(26);
        
        for (string &word : words) {
            for (char c = 'a'; c <= 'z'; ++c) {
                w2p[c] = '\0';
                p2w[c] = '\0';
            }
            
            bool is_match = true;
            
            for (int j = 0; j < n; ++j) {
                if (w2p[word[j]] != '\0' && w2p[word[j]] != pattern[j]) {
                    is_match = false;
                    break;
                }
                
                if (p2w[pattern[j]] != '\0' && p2w[pattern[j]] != word[j]) {
                    is_match = false;
                    break;
                }
                
                w2p[word[j]] = pattern[j];
                p2w[pattern[j]] = word[j];
            }
            
            if (is_match) {
                matches.push_back(word);
            }
        }
        
        return matches;
    }
};
