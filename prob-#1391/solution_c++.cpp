class Solution {
public:
    vector<vector<bool>> reached;
    // up, right, down, left
    vector<vector<bool>> reachable = {
        {false, true, false, true},
        {true, false, true, false},
        {false, false, true, true},
        {false, true, true, false},
        {true, false, false, true},
        {true, true, false, false}
    };

    void traverse(vector<vector<int>>& grid, int m_idx, int n_idx) {
        int m = grid.size();
        int n = grid[0].size();
        reached[m_idx][n_idx] = true;

        if(m_idx == m - 1 && n_idx == n - 1) {
            return;
        }

        int street = grid[m_idx][n_idx];
        vector<int> go_to1 = {m_idx, n_idx};
        vector<int> go_to2 = {m_idx, n_idx};
        int direction1 = 4;
        int direction2 = 4;
        bool can_reach1 = false;
        bool can_reach2 = false;
        
        switch (street) {
            case 1:
                if(n_idx > 0) { direction1 = 3; go_to1[1] = max(0, n_idx - 1); }
                if(n_idx < n - 1) { direction2 = 1; go_to2[1] = min(n - 1, n_idx + 1); }
                break;
            case 2:
                if(m_idx > 0) { direction1 = 0; go_to1[0] = max(0, m_idx - 1); }
                if(m_idx < m - 1) { direction2 = 2; go_to2[0] = min(m - 1, m_idx + 1); }
                break;
            case 3:
                if(n_idx > 0) { direction1 = 3; go_to1[1] = max(0, n_idx - 1); }
                if(m_idx < m - 1) { direction2 = 2; go_to2[0] = min(m - 1, m_idx + 1); }
                break;
            case 4:
                if(n_idx < n - 1) { direction1 = 1; go_to1[1] = min(n - 1, n_idx + 1); }
                if(m_idx < m - 1) { direction2 = 2; go_to2[0] = min(m - 1, m_idx + 1); }
                break;
            case 5:
                if(n_idx > 0) { direction1 = 3; go_to1[1] = max(0, n_idx - 1); }
                if(m_idx > 0) { direction2 = 0; go_to2[0] = max(0, m_idx - 1); }
                break;
            case 6:
                if(m_idx > 0) { direction1 = 0; go_to1[0] = max(0, m_idx - 1); }
                if(n_idx < n - 1) { direction2 = 1; go_to2[1] = min(n - 1, n_idx + 1); }
                break;
            default:
                break;
        }

        if(direction1 != 5) { 
            can_reach1 = reachable[street - 1][direction1] 
                        && reachable[grid[go_to1[0]][go_to1[1]] - 1][(direction1 + 2) % 4]; 
        }
        if(direction2 != 5) { 
            can_reach2 = reachable[street - 1][direction2] 
                        && reachable[grid[go_to2[0]][go_to2[1]] - 1][(direction2 + 2) % 4]; 
        }

        if(can_reach1 && reached[go_to1[0]][go_to1[1]] == false) { 
            traverse(grid, go_to1[0], go_to1[1]); 
        }
        if(can_reach2 && reached[go_to2[0]][go_to2[1]] == false) { 
            traverse(grid, go_to2[0], go_to2[1]); 
        }

        return;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        reached.assign(m, vector<bool>(n, false));
        
        traverse(grid, 0, 0);

        return reached[m - 1][n - 1];
    }
};
