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
    struct array_string_iterator {
    private:
    vector<string>& word;
    vector<string>::iterator i = word.begin();
    string::iterator j = word[0].begin();
    
    public:
    array_string_iterator(vector<string>& word) : word(word) {
        // nothing to do here
    }
    
    vector<string>::iterator end() {
        return word.end();
    }
    
    bool operator!= (vector<string>::iterator b) {
        return i != b;
    }
    
    auto& operator* () {
        return *j;
    }
    
    void operator++ () {
        ++j;
        
        if (j == i->end()) {
            ++i;
            
            if (i != word.end())
                j = i->begin();
        }
    }
};
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        array_string_iterator a(word1);
        array_string_iterator b(word2);
        
        while (a != a.end() && b != b.end()) {
            // cout << *a << " " << *b << endl;
            
            if (*a != *b)
                return false;
            ++a;
            ++b;
        }
    
        // cout << *a << " " << *b << endl;
        // One of is at the end, but are both?
        return *a == *b;
    }
};