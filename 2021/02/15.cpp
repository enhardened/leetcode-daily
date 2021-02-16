/**
Problem: https://leetcode.com/explore/item/3641
Title: The K Weakest Rows in a Matrix
*/
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<tuple<int, int>> data(mat.size());
        
        for (int i = 0; i < mat.size(); ++i) {
            int soldierCount = 0;

            for (int j = 0; j < mat[i].size() && mat[i][j] == 1; ++j)
                ++soldierCount;
            
            data[i] = make_tuple(soldierCount, i);
        }
        
        sort(data.begin(), data.end(), [](tuple<int, int> a, tuple<int, int> b) {
            return get<0>(a) < get<0>(b) || (get<0>(a) == get<0>(b) && get<1>(a) < get<1>(b));
        });
        
        vector<int> result(k);
        
        for (int i = 0; i < k; ++i) {
            result[i] = get<1>(data[i]);
        }
        
        return result;
    }
};