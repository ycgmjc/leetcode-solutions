class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> visited(n, false);

        stack<int> to_traverse;
        to_traverse.push(0);
        visited[0] = true;
        while(to_traverse.empty() == false) {
            int index = to_traverse.top();
            to_traverse.pop();
            int left_limit = max(0, index - nums[index]);
            int right_limit = min(n - 1, index + nums[index]);
            if(right_limit == n - 1) { return true; }

            for(int i = left_limit; i <= right_limit; i++) {
                if(visited[i] == false) { visited[i] = true; to_traverse.push(i); }
            }
        }
        
        return false;
    }
};
