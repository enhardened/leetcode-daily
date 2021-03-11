// Problem: https://leetcode.com/explore/item/3667
class Solution {
public:
    string intToRoman(int num) {
        string roman = "";
        
        pair<char, int> numerals[7] = {
            {'I', 1},   {'V', 5}, 
            {'X', 10},  {'L', 50}, 
            {'C', 100}, {'D', 500}, 
            {'M', 1000},
        };
        
        for (int i = 6; i >= 0 ; i -= 2) {
            while (num >= numerals[i].second) {
                roman += numerals[i].first;
                num -= numerals[i].second;
            }
            
            if (i == 0) break;
            
            // 9*
            int helper = numerals[i].second - numerals[i-2].second;
            if (num >= helper) {
                roman += numerals[i-2].first ;
                roman += numerals[i].first;
                num -= helper;
            }
            
            // 5*
            if (num >= numerals[i-1].second) {
                roman += numerals[i-1].first;
                num -= numerals[i-1].second;
            }
            
            // 4*
            helper = numerals[i-1].second - numerals[i-2].second;
            if (num >= helper) {
                roman += numerals[i-2].first;
                roman += numerals[i-1].first;
                num -= helper;
            }
        }
        
        return roman;
    }
};
