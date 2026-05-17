class Solution {
public:
    vector<int> get_dest(vector<int>& arr, int idx) {
        if(arr[idx] == 0) { return {-1}; }
        vector<int> output;
        int n = arr[idx];
        if(idx - n >= 0) {
            output.push_back(idx - n);
        }
        if(idx + n < arr.size()) {
            output.push_back(idx + n);
        }
        return output;
    }

    bool traverse(vector<int>& arr, vector<bool>& visited, int idx) {
        int n = arr.size();
        visited[idx] = true;
        int num = arr[idx];
        if(num == 0) { return true; }

        vector<int> to_visit = get_dest(arr, idx);
        for(int dest : to_visit) {
            if(visited[dest] == true) { continue; }
            if(traverse(arr, visited, dest) == true) { return true; }
        }

        return false;
    }

    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        
        return traverse(arr, visited, start);
    }
};
