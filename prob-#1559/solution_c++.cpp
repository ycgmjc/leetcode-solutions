class Solution {
public:
    void reset_visits(vector<int>& visited_idx, vector<vector<int>>& visit_status, int n) {
        for(int idx : visited_idx) {
            int n_idx = idx % n;
            int m_idx = idx / n;
            visit_status[m_idx][n_idx] = 2;
        }
        visited_idx = {};
    }

    int check_right(vector<vector<char>>& grid, vector<vector<int>>& visit_status, int m_idx, int n_idx) {
        if(n_idx >= grid[0].size() - 1) { return 2; }
        else { 
            if(grid[m_idx][n_idx] == grid[m_idx][n_idx + 1]) {
                return visit_status[m_idx][n_idx + 1];
            }
            else { return 2; }
        }
    }

        int check_down(vector<vector<char>>& grid, vector<vector<int>>& visit_status, int m_idx, int n_idx) {
        if(m_idx >= grid.size() - 1) { return 2; }
        else { 
            if(grid[m_idx][n_idx] == grid[m_idx + 1][n_idx]) {
                return visit_status[m_idx + 1][n_idx];
            }
            else { return 2; }
        }
    }

    int check_left(vector<vector<char>>& grid, vector<vector<int>>& visit_status, int m_idx, int n_idx) {
        if(n_idx == 0) { return 2; }
        else { 
            if(grid[m_idx][n_idx] == grid[m_idx][n_idx - 1]) {
                return visit_status[m_idx][n_idx - 1];
            }
            else { return 2; }
        }
    }

        int check_up(vector<vector<char>>& grid, vector<vector<int>>& visit_status, int m_idx, int n_idx) {
        if(m_idx == 0) { return 2; }
        else { 
            if(grid[m_idx][n_idx] == grid[m_idx - 1][n_idx]) {
                return visit_status[m_idx - 1][n_idx];
            }
            else { return 2; }
        }
    }

    bool traverse(vector<vector<char>>& grid, vector<vector<int>>& visit_status, vector<int>& visited_idx, int m_idx, int n_idx, string from) {
        int m = grid.size();
        int n = grid[0].size();
        bool detect = false;
        int right = check_right(grid, visit_status, m_idx, n_idx);
        int left = check_left(grid, visit_status, m_idx, n_idx);
        int up = check_up(grid, visit_status, m_idx, n_idx);
        int down = check_down(grid, visit_status, m_idx, n_idx);

        visited_idx.push_back(m_idx * n + n_idx);
        visit_status[m_idx][n_idx] = 1;

        if(from == "left") { 
            detect = right == 1 || up == 1 || down == 1;
        }
        else if(from == "up") { 
            detect = right == 1 || left == 1 || down == 1;
        }
        else if(from == "right") { 
            detect = left == 1 || up == 1 || down == 1;
        }
        else if(from == "down") { 
            detect = right == 1 || up == 1 || left == 1;
        }

        if(detect == true) { return true; }
        else {
            bool traverse_right = false;
            bool traverse_left = false;
            bool traverse_up = false;
            bool traverse_down = false;
            if(right == 0) { traverse_right = traverse(grid, visit_status, visited_idx, m_idx, n_idx + 1, "left"); }
            if(left == 0) { traverse_left = traverse(grid, visit_status, visited_idx, m_idx, n_idx - 1, "right"); }
            if(up == 0) { traverse_up = traverse(grid, visit_status, visited_idx, m_idx - 1, n_idx, "down"); }
            if(down == 0) { traverse_down = traverse(grid, visit_status, visited_idx, m_idx + 1, n_idx, "up"); }
            return traverse_right || traverse_left || traverse_up || traverse_down;
        }
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visit_status(m, vector<int>(n, 0));
        vector<int> visited_idx(m * n);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(visit_status[i][j] == 0) {
                    bool cycle_detect = traverse(grid, visit_status, visited_idx, i, j, "");
                    if(cycle_detect) { return true; }
                    reset_visits(visited_idx, visit_status, n);
                }
            }
        }
        return false;
    }
};
