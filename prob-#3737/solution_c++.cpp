class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int result = 0;
        vector<int> is_target(n, 0);
        for(int i = 0; i < n; i++) {
            if(nums[i] == target) {
                is_target[i] = 1;
            }
        }

        for(int i = 0; i < n; i++) {
            int matched = 0;
            for(int j = i; j < n; j++) {
                int required = (j - i + 1) / 2 + 1;
                matched += is_target[j];
                if(matched >= required) { result += 1; }
            }
        }

        return result;
    }
};
