// Problem: Vowel Spellchecker
// URL: https://leetcode.com/explore/item/3681
class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        int n = queries.size(),
            m = wordlist.size();
        
        vector<string> answer;
        answer.reserve(n);
        
        unordered_set<string> words;
        words.reserve(m);
        
        unordered_map<string, string> capitalization_map;
        capitalization_map.reserve(m);
        
        unordered_map<string, string> vowel_neutral_map;
        vowel_neutral_map.reserve(m);
        
        for (auto word : wordlist) {
            string lowercased = toLowerCase(word);
            
            words.insert(word);
            
            if (capitalization_map.count(lowercased) == 0)
                capitalization_map[lowercased] = word;
            
            if (vowel_neutral_map.count(toVowelNeutral(lowercased)) == 0)
                vowel_neutral_map[toVowelNeutral(lowercased)] = word;
        }
        
        for (auto query : queries) {
            if (words.count(query) > 0) {
                answer.push_back(query);
                continue;
            }
            
            string lowercased = toLowerCase(query);
            
            if (capitalization_map.count(lowercased) > 0) {
                answer.push_back(capitalization_map[lowercased]);
                continue;
            }
            
            string vowel_neutral = toVowelNeutral(lowercased);
            
            if (vowel_neutral_map.count(vowel_neutral)) {
                answer.push_back(vowel_neutral_map[vowel_neutral]);
                continue;
            }
            
            answer.push_back("");
        }
        
        return answer;
    }
    
    string toLowerCase(string word) {
        for (auto &c : word)
            if (c >= 'A' && c <= 'Z')
                c = (c - 'A') + 'a';
        
        return word;
    }
    
    string toVowelNeutral(string word) {
        for (auto &c : word) 
            switch (c) {
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    c = 'a';
            }
        
        return word;
    }
};