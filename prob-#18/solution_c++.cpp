class Solution {
public:
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> output;
        sort(nums.begin(), nums.end());
        int left1 = 0;
        int left2 = 1;
        int left_idx = 2;
        int right_idx = nums.size() - 2;
        long long sum = 0;

        if(nums.size() < 4) { return output; }

        while(left1 < nums.size() - 3) {
            int num1 = nums[left1];
            left2 = left1 + 1;
            while(left2 < nums.size() - 2) {
                int num2 = nums[left2];
                left_idx = left2 + 1;
                right_idx = nums.size() - 1;

                while(left_idx < right_idx) {
                    int num3 = nums[left_idx];
                    int num4 = nums[right_idx];
                    sum = (long long)num1 + num2 + num3 + num4;

                    if(sum == target) {
                        output.push_back({num1, num2, num3, num4});
                        while(nums[left_idx] == num3 && left_idx < right_idx) { left_idx += 1;}
                        while(nums[right_idx] == num4 && left_idx < right_idx) { right_idx -= 1;}
                    }
                    
                    else if(sum < target) {
                        while(nums[left_idx] == num3 && left_idx < right_idx) { left_idx += 1;}
                    }
                    else {
                        while(nums[right_idx] == num4 && left_idx < right_idx) { right_idx -= 1;}
                    }
                }
                while(nums[left2] == num2 && left2 < nums.size() - 2) { left2 += 1; }
            }
            while(nums[left1] == num1 && left1 < nums.size() - 3) { left1 += 1; }
        }

        return output;
    }
};
