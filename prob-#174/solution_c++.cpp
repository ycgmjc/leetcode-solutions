class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        
        vector<vector<int>> health(m + 1, vector<int>(n + 1, INT_MAX));
        
        health[m][n - 1] = 1;
        health[m - 1][n] = 1;
        
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                
                int min_health_on_exit = min(health[i + 1][j], health[i][j + 1]);
                
                health[i][j] = max(1, min_health_on_exit - dungeon[i][j]);
            }
        }
        
        return health[0][0];
    }
};
