// Problem: https://leetcode.com/explore/item/3669
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> codes;
        int expectedSize = 1 << k;
        
        if (s.length() < expectedSize + k - 1)
            return false;
        
        int n = s.length() - k;
        
        for (int i = 0; i <= n && codes.size() < expectedSize; ++i)
            codes.insert(s.substr(i, k));
        
        return codes.size() == expectedSize;
    }
};
