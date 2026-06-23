class NumMatrix {
    vector<vector<int>> _matrix;
    int m = 0;
    int n = 0;

    std::map<vector<int>, int> cache;

    void update_cache(int row1, int col1, int row2, int col2, int sum) {
        vector<int> temp = {row1, col1, row2, col2};
        cache[temp] = sum;
    }
public:
    NumMatrix(vector<vector<int>>& matrix) {
        _matrix = matrix;
        m = matrix.size();
        n = matrix[0].size();
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(!(m | n)) { return -1; }

        if(cache.contains({row1, col1, row2, col2})) { return cache[{row1, col1, row2, col2}]; }

        int result = 0;
        for(int i = row1; i <= row2; i++) {
            for(int j = col1; j <= col2; j++) {
                result += _matrix[i][j];
            }
        }

        update_cache(row1, col1, row2, col2, result);
        return result;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
