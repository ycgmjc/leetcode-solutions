class Solution {
public:
    // you can divide the list into connected groups
    // each group has the value of the largest number in that group
    // groups can be identified by seeing if the largest number
    // of the left is smaller than the smallest number of the right
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return nums;
        
        vector<int> pref_max(n);
        vector<int> suff_min(n);
        
        // prefix maximums
        pref_max[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pref_max[i] = max(pref_max[i - 1], nums[i]);
        }
        
        // suffix minimums
        suff_min[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suff_min[i] = min(suff_min[i + 1], nums[i]);
        }
        
        vector<int> result(n);
        int current_component_start = 0;
        
        for (int i = 0; i < n; i++) {
            if (i == n - 1 || pref_max[i] <= suff_min[i + 1]) {
                int comp_max = pref_max[i];
                for (int j = current_component_start; j <= i; j++) {
                    result[j] = comp_max;
                }
                current_component_start = i + 1;
            }
        }
        
        return result;
    }
};
