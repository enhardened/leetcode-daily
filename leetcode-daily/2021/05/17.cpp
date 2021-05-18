// Problem: Longest String Chain
// URL: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/600/week-3-may-15th-may-21st/3746/
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size(),
            result = 0,
            min_l = INT_MAX,
            max_l = INT_MIN;
        
        vector<vector<string*>> words_by_length(16);
        vector<vector<int>> memo(17);
        
        for (int i = 0, l; i < n; ++i) {
            l = words[i].length();
            min_l = min(min_l, l);
            max_l = max(max_l, l);
            words_by_length[l-1].push_back(&words[i]);
        }
        
        for (int i = 0; i < 16; ++i) {            
            for (int j = 0, n = words_by_length[i].size(), best; j < n; ++j) {
                best = 1;
                                
                for (int k = 0, m = memo[i].size(); k < m; ++k) {
                    bool match = true;
                    
                    for (int l1 = 0, l2 = 0; l1 <= i; ++l1) {
                        if (l1 == i && l2 == l1)
                            break;
                        if ((*words_by_length[i][j])[l1] == (*words_by_length[i-1][k])[l2])
                            l2++;
                        else if (l1 != l2) {
                            match = false;
                            break;
                        }
                    }
                    
                    if (match)
                        best = max(best, memo[i][k]+1);
                }
                
                memo[i+1].push_back(best);
                result = max(result, best);
            }
            
        }
        /*
        for (int i = 0; i < 17; ++i) {
            cout << i << ": ";
            for (int j = 0; j < memo[i].size(); ++j) {
                cout << memo[i][j] << " ";
            }
            
            cout << endl;
        }
        */
        return result;
    }
};
