class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> is_0(m + n, false);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) { is_0[i] = true; is_0[m + j] = true; }
            }
        }

        for(int i = 0; i < m; i++) {
            if(is_0[i] == true) {
                for(int j = 0; j < n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            if(is_0[m + i] == true) {
                for(int j = 0; j < m; j++) {
                    matrix[j][i] = 0;
                }
            }
        }
        
    }
};
