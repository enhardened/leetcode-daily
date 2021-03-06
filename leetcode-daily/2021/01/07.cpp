/*
Problem: https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/579/week-1-january-1st-january-7th/3595/
Title: Longest Substring Without Repeating Characters
Description:
Given a string s, find the length of the longest substring without repeating characters.
---
Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
---
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
---
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
---
Example 4:

Input: s = ""
Output: 0
---

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int offset = 0,
            result = 0;
        
        unordered_map<char, int> last_pos;
        
        for (int i = 0; i < s.size(); i++) {
            if (last_pos.count(s[i]) && last_pos[s[i]] >= offset)
                offset = last_pos[s[i]] + 1;
            result = max(result, i - offset + 1);
            last_pos[s[i]] = i;
        }
        
        return result;
    }
};
