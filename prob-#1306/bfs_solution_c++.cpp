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

    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        queue<int> to_visit;
        to_visit.push(start);
        
        while(!to_visit.empty()) {
            int idx = to_visit.front();
            to_visit.pop();
            visited[idx] = true;

            if(arr[idx] == 0) { return true; }

            vector<int> destinations = get_dest(arr, idx);
            for(int num : destinations) {
                if(visited[num] == true) { continue; }
                to_visit.push(num);
            }
        }
        return false;
    }
};
