/**
Problem: https://leetcode.com/explore/item/3641
Title: The K Weakest Rows in a Matrix
*/
class Solution {
public:
    int countSoldiers(vector<int>& row) 
    {
        int l = 0;
        int r = row.size();
        int m;
        
        while (l < r) {
            m = (l + r) / 2;
            
            if (row[m] == 1) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        
        return l;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> data(mat.size());
        
        for (int i = 0; i < mat.size(); ++i) {
            data[i].first = countSoldiers(mat[i]);
            data[i].second = i;
        }
        
        sort(data.begin(), data.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.first < b.first || (a.first == b.first && a.second < b.second);
        });
        
        vector<int> result(k);
        
        for (int i = 0; i < k; ++i) {
            result[i] = data[i].second;
        }
        
        return result;
    }
};
