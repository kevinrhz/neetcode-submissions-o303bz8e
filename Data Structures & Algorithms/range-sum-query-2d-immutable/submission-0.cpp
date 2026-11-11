class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        sumMatrix_ = std::vector<std::vector<int>>(ROWS + 1, std::vector<int>(COLS + 1, 0));
        for (size_t r = 0; r < ROWS; ++r) {
            int prefix = 0;
            for (size_t c = 0; c < COLS; ++c) {
                prefix += matrix[r][c];
                int above = sumMatrix_[r][c + 1];
                sumMatrix_[r + 1][c + 1] = prefix + above;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        ++row1; ++col1; ++row2; ++col2;
        int bottomRight = sumMatrix_[row2]    [col2];
        int above       = sumMatrix_[row1 - 1][col2];
        int left        = sumMatrix_[row2]    [col1 - 1];
        int topLeft     = sumMatrix_[row1 - 1][col1 - 1];
        return bottomRight - above - left + topLeft;
    }

private:
    std::vector<std::vector<int>> sumMatrix_;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */