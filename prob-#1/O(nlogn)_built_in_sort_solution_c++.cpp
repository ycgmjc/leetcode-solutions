class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int left_idx = 0;
        int right_idx = sorted.size() - 1;

        while(left_idx < right_idx) {
            int sum = sorted[left_idx] + sorted[right_idx];
            if(sum == target) { break; }
            if(sum < target) {
                left_idx += 1;
            }
            else {
                right_idx -= 1;
            }
        }

        int idx1 = -1;
        int idx2 = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == sorted[left_idx] && idx1 == -1) {
                idx1 = i;
            } 
            else if(nums[i] == sorted[right_idx] && idx2 == -1) {
                idx2 = i;
            }
        }

        if(idx1 > idx2) {
            return vector<int>{idx2, idx1};
        }

        return vector<int>{idx1, idx2};
    }
};
