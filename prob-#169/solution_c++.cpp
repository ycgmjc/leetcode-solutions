class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) { return nums[0]; }

        sort(nums.begin(), nums.end());
        
        int counter = 1;
        int limit = n / 2;
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i - 1]) { counter += 1; }
            else { counter = 1; }
            if(counter > limit) { return nums[i]; }
        }
        return -1;
    }
};
