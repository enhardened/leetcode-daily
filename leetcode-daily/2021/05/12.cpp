// Problem: Range Sum Query 2D - Immutable
// URL: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/599/week-2-may-8th-may-14th/3740/
class NumMatrix {
private:
    
public:
    vector<vector<int>> memo;
    
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(),
            n = matrix[0].size() + 1;
        
        memo.resize(m, vector<int>(n));
        
        for (int i = 0; i < m; ++i) {
            memo[i][0] = 0;
            for (int j = 1; j < n; ++j) {
                memo[i][j] = memo[i][j-1] + matrix[i][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        
        for (int i = row1; i <= row2; ++i) {
            sum += memo[i][col2 + 1] - memo[i][col1];
        }
        
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */