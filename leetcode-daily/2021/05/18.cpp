// Problem: Find Duplicate File in System
// URL: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/600/week-3-may-15th-may-21st/3747/
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> content_to_files;
        
        for (auto &row : paths) {
            int l = 0,
                r = 0;
            
            // Search the end of dirname
            while (row[r] != ' ')
                ++r;
            
            string dirname = row.substr(l, r-l);
            // cout << "found dir: " << dirname << '\n';
            
            int n = row.length();
            
            while (r < n) {
                // Search the end of filename
                l = ++r; // skip ' '
                while (row[r] != '(')
                    ++r;
                
                string filename = row.substr(l, r-l);
                // cout << "found file: " << filename << '\n';
                
                // Search the end of content
                l = ++r; // skip '('
                while (row[r] != ')')
                    ++r;
                
                string content = row.substr(l, r-l);
                // cout << "found content: " << content << '\n';
                                
                content_to_files[content].push_back(dirname + "/" + filename);
                
                ++r; // skip ')'
            }
        }
        
        vector<vector<string>> result;
        
        for (auto &pair : content_to_files)
            if (pair.second.size() > 1)
                result.push_back(pair.second);
        
        return result;
    }
};
