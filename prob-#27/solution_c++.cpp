class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int idx = 0;
        int output = 0;
        while(idx < nums.size()) {
            while(idx < nums.size() && val == nums[idx]) {
                idx += 1;
            }
            if(idx > nums.size() - 1) { break; }
            nums[output] = nums[idx];
            output += 1;
            idx += 1;
        }

        return output;
    }
};
