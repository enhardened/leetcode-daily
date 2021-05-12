// Problem: Range Sum Query 2D - Immutable
// URL: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/599/week-2-may-8th-may-14th/3740/
// Naive solution (Timed out)
class NumMatrix {
private:
    vector<vector<int>> *matrix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = &matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        
        for (int i = row1; i <= row2; ++i) {
            for (int j = col1; j <= col2; ++j) {
                sum += (*matrix)[i][j];
            }
        }
        
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */