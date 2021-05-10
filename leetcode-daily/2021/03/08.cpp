// Problem: https://leetcode.com/explore/item/3665
class Solution {
public:
    bool isPalindrome(string &s) {
        int l = 0,
            r = s.length() -1;
        
        while (l < r)
            if (s[l++] != s[r--])
                return false;
        
        return true;
    }
    
    int removePalindromeSub(string s) {
        if (s == "")
            return 0;
        
        if (isPalindrome(s))
            return 1;
        
        return 2;
    }
};
