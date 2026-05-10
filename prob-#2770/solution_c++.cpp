class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> max_jumps(n, -1);
        max_jumps[0] = 0;

        for(int idx = 1; idx < n; idx++) {
            int prev_max = -2;
            for(int i = 0; i < idx; i++) {
                if(abs(nums[idx] - nums[i]) <= target && 
                max_jumps[i] != -1 && 
                prev_max < max_jumps[i]) {
                    prev_max = max_jumps[i];
                }
            }
            max_jumps[idx] = prev_max + 1;
        }

        return max_jumps[n - 1];
    }
};
