/*
Problem: https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/580/week-2-january-8th-january-14th/3597/
Title: Check If Two String Arrays are Equivalent
Description: 

Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.

A string is represented by an array if the array elements concatenated in order forms the string.

---
Example 1:

Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
Output: true
Explanation:
word1 represents string "ab" + "c" -> "abc"
word2 represents string "a" + "bc" -> "abc"
The strings are the same, so return true.
---
Example 2:

Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
Output: false
---
Example 3:

Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
Output: true
--- 

Constraints:

1 <= word1.length, word2.length <= 103
1 <= word1[i].length, word2[i].length <= 103
1 <= sum(word1[i].length), sum(word2[i].length) <= 103
word1[i] and word2[i] consist of lowercase letters.
*/

class Solution {
public:
    /*
    This functions was refactored on whiteboard. It's not exactly the first version.

    w: "word" array
    i: word index
    j: letter index
    */
    void updateIndexes(vector<string>& w, int& i, int& j) {
        if (j + 1 < w[i].length())
            // the ith word didn't finished
            j += 1;
        else {
            // going to the next word
            i += 1;
            j = 0;
        }
    }
    
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i1 = 0, j1 = 0,
            i2 = 0, j2 = 0;
        
        while (i1 < word1.size() && i2 < word2.size()) {
            if (word1[i1][j1] != word2[i2][j2])
                return false;
            
            updateIndexes(word1, i1, j1);
            updateIndexes(word2, i2, j2);
        }
        
        // Are they both at the end? (are both "words" the same size?)
        int last_i1 = word1.size(); // while stop when i == word.size()
        int last_i2 = word2.size();
        int last_j1 = word1[last_i1 - 1].size() - 1;
        int last_j2 = word1[last_i2 - 1].size() - 1;
       
        return (i1 == word1.size() && i2 == word2.size() 
                && j1 == 0 && j2 == 0);
    }
};