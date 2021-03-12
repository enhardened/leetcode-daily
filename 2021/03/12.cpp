// Problem: https://leetcode.com/explore/item/3669
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> codes;
        int expectedSize = pow(2, k),
            n = s.length() - k;
        
        for (int i = 0; i <= n && codes.size() < expectedSize; ++i)
            codes.insert(s.substr(i, k));
        
        return codes.size() == expectedSize;
    }
};
