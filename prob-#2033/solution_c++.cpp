class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> flat;
        for(vector<int> vec : grid) {
            for(int i : vec) {
                flat.push_back(i);
            }
        }
        sort(flat.begin(), flat.end());
        
        int target = flat[flat.size() / 2];
        int total_changes = 0;
        
        for(int num : flat) {
            int sub = abs(num - target);
            if(sub % x != 0) { return -1; }
            total_changes += sub / x;
        }
        
        return total_changes;
    }
};
