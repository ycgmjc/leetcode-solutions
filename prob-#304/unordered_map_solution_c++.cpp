class NumMatrix {
    vector<vector<int>> _matrix;
    int m = 0;
    int n = 0;

    unordered_map<string, int> cache;

    string encode(int row1, int col1, int row2, int col2) {
        return to_string(row1) + to_string(row2) + to_string(col1) + to_string(col2);
    }

    void update_cache(int row1, int col1, int row2, int col2, int sum) {
        string code = encode(row1, col1, row2, col2);
        cache[code] = sum;
    }
public:
    NumMatrix(vector<vector<int>>& matrix) {
        _matrix = matrix;
        m = matrix.size();
        n = matrix[0].size();
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(!(m | n)) { return -1; }

        string code = encode(row1, col1, row2, col2);
        if(cache.contains(code)) { return cache[code]; }

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
 