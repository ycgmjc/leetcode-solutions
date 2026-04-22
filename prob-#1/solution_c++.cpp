class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int idx1;
        int idx2;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int num1 = nums[i];
                int num2 = nums[j];
                if(num1 + num2 == target) {
                    idx1 = i;
                    idx2 = j;
                    break;
                }
            }
        }
        return vector<int>{idx1, idx2};
    }
};
