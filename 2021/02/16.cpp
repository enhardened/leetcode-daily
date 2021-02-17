/*
Problem: https://leetcode.com/problems/letter-case-permutation/
Title: Letter Case Permutation
*/
class Solution {
public:
    bool isLowerCaseLetter(char c) {
        return c >= 'a' && c <= 'z';
    }
    
    bool isUpperCaseLetter(char c) {
        return c >= 'A' && c <= 'Z';
    }
    
    bool isLetter(char c) {
        return isLowerCaseLetter(c) || isUpperCaseLetter(c);
    }
    
    char switchCase(char c) {
        if (isLowerCaseLetter(c))
            return c + ('A' - 'a');
        else
            return c - ('A' - 'a');
    }
    
    vector<string> letterCasePermutation(string S) {
        int n = S.length();
        int numberOfLetters = 0;
        
        // O(n)
        for (int i = 0; i < n; ++i)
            if (isLetter(S[i])) 
                ++numberOfLetters;
        
        int numberOfPermutations = pow(2, numberOfLetters);
        vector<string> result(numberOfPermutations);
        
        int alternatingGroupsSize = numberOfPermutations;
        
        for (int i = 0; i < n; ++i) {
            if (isLetter(S[i]))
                alternatingGroupsSize = alternatingGroupsSize / 2; 
            
            for (int j = 0; j < numberOfPermutations; ++j) {
                if (!isLetter(S[i])) {
                    result[j] += S[i];
                    continue;
                }
                
                result[j] += (j/alternatingGroupsSize) % 2 == 0
                    ? S[i]
                    : switchCase(S[i]);
            }
        }
        
        return result;
    }
};
