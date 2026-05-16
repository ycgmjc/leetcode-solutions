class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;
        while(nums[idx] <= nums[(idx + 1) % n]) {
            idx = (idx + 1) % n;
            if(idx == 0) { break; }
        }
        return nums[(idx + 1) % n];
    }
};
