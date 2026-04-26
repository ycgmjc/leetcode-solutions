class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int best = nums[0] + nums[1] + nums[2];

        for(int i = 0; i < nums.size() - 2; i++) {
            int left_idx = i + 1;
            int right_idx = nums.size() - 1;
            
            while(left_idx < right_idx) {
                int current_sum = nums[i] + nums[left_idx] + nums[right_idx];
                
                if (abs(current_sum - target) < abs(best - target)) {
                    best = current_sum;
                }

                if (best == target) { return best; }
                
                if (current_sum < target) { left_idx += 1; } 
                else { right_idx -= 1; }
            }
        }

        return best;
    }
};
