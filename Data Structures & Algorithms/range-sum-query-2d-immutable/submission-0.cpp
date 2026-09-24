class NumMatrix {
    private:
    vector<vector<int>> res;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        res = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        /*
        row1 = left
        col1 = top
        row2 = bottom
        col2 = right
        */
        int sum = 0;
        for(int i = row1; i <= row2; i++)
        {
            for(int j = col1; j <= col2; j++)
            {
                sum += res[i][j];
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