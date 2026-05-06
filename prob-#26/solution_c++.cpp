class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev_num = nums[0];
        int idx = 1;
        int output = 1;
        while(idx < nums.size()) {
            while(idx < nums.size() && prev_num == nums[idx]) {
                idx += 1;
            }
            if(idx > nums.size() - 1) { break; }
            nums[output] = nums[idx];
            prev_num = nums[idx];
            output += 1;
        }

        return output;
    }
};
