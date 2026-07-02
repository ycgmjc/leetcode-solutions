class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> damage(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> to_visit;
        
        int startDamage = grid[0][0];
        damage[0][0] = startDamage;
        to_visit.push_back({0, 0});
        
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!to_visit.empty()) {
            auto [r, c] = to_visit.front();
            to_visit.pop_front();
            
            if (r == m - 1 && c == n - 1) {
                return health - damage[r][c] > 0; 
            }
            
            for (auto& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int newDamage = damage[r][c] + grid[nr][nc];
                    
                    if (newDamage < damage[nr][nc]) {
                        damage[nr][nc] = newDamage;
                        
                        if (grid[nr][nc] == 0) {
                            to_visit.push_front({nr, nc});
                        } 
                        else {
                            to_visit.push_back({nr, nc});
                        }
                    }
                }
            }
        }
        
        return false;
    }
};
