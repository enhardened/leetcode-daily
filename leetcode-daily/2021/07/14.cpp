// https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3813/
// Title: Custom Sort String
class Solution {
public:
    string customSortString(string order, string str) {
        vector<int> char_count(26, 0);
        
        for (char &c : str) {
            char_count[c - 'a']++;
        }
        
        int i = 0;
        
        // Recreate the string in other
        for (char &c : order) {
            while (char_count[c - 'a']-- > 0) {
                str[i++] = c;
            }
        }
        
        // Add characters not present in sort to the end of the string
        for (int j = 0; j < 26; j++) {
            while (char_count[j]-- > 0) {
                str[i++] = ('a' + j);
            }
        }
        
        return str;
    }
};
