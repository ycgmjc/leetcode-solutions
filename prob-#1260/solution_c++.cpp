class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> output = grid;

        for(int repeat = 0; repeat < k; repeat++) {
            int new_val = output[m - 1][n - 1];
            int old_val = output[0][0];
            for(int i = 0; i < m * n; i++) {
                output[i / n][i % n] = new_val;
                if(i == m * n - 1) { break; }
                new_val = old_val;
                old_val = grid[(i + 1) / n] [(i + 1) % n];
            }
            grid = output;
        }

        return output;
    }
};
