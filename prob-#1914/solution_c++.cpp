class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int layers = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> answer(m, vector<int>(n, 0));
        if(m < n) {
            layers = m / 2;
        }
        else {
            layers = n / 2;
        }

        
        for(int i = 0; i < layers; i++) {
            vector<int> strip;
            // make a strip of the layer
            for(int j = i; j < n - i - 1; j++) {
                strip.push_back(grid[i][j]);
            }
            for(int j = i; j < m - i - 1; j++) {
                strip.push_back(grid[j][n - i - 1]);
            }
            for(int j = n - i - 1; j > i; j--) {
                strip.push_back(grid[m - i - 1][j]);
            }
            for(int j = m - i - 1; j > i; j--) {
                strip.push_back(grid[j][i]);
            }

            int idx = k;
            int len = strip.size();
            // rotate and apply the layer
            for(int j = i; j < n - i - 1; j++) {
                answer[i][j] = strip[idx % len];
                idx += 1;
            }
            for(int j = i; j < m - i - 1; j++) {
                answer[j][n - i - 1] = strip[idx % len];
                idx += 1;
            }
            for(int j = n - i - 1; j > i; j--) {
                answer[m - i - 1][j] = strip[idx % len];
                idx += 1;
            }
            for(int j = m - i - 1; j > i; j--) {
                answer[j][i] = strip[idx % len];
                idx += 1;
            }
        }
        return answer;
    }
};
