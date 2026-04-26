class Solution {
public:
    vector<int> merge(vector<int>& num1, vector<int>& num2) {
        vector<int> merged;
        int idx1 = 0;
        int idx2 = 0;

        while(idx1 < num1.size() && idx2 < num2.size()) {
            if(num1[idx1] < num2[idx2]) {
                merged.push_back(num1[idx1]);
                idx1 += 1;
            } 
            else if(num1[idx1] > num2[idx2]) {
                merged.push_back(num2[idx2]);
                idx2 += 1;
            }
            else {
                merged.push_back(num1[idx1]);
                idx1 += 1;
                idx2 += 1;
            }
        }

        while(idx1 < num1.size()) {
            merged.push_back(num1[idx1]);
            idx1 += 1;
        }

        while(idx2 < num2.size()) {
            merged.push_back(num2[idx2]);
            idx2 += 1;
        }

        return merged;
    }

    vector<int> merge_sort(vector<int>& nums) {
        if(nums.size() <= 1) {
            return nums;
        }

        int half_size = nums.size() / 2;

        vector<int> left(nums.begin(), nums.begin() + half_size);
        vector<int> right(nums.begin() + half_size, nums.end());

        vector<int> bucket1 = merge_sort(left);
        vector<int> bucket2 = merge_sort(right);

        return merge(bucket1, bucket2);
    }

    bool is_used(vector<int> used_nums, int num) {
        if(used_nums.size() == 0) { return false; }
        for(int i : used_nums) { if(i == num) { return true; }}
        return false;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        int length = nums.size();

        // 1. Find case with duplicates
        vector<int> used_nums;
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if(num % 2 == 1 || num % 2 == -1 || is_used(used_nums, num)) { continue; }

            int target = 0 - num / 2;
            int target_count = 0;
            int valid = false;
            for(int j = 0; j < nums.size(); j++) {
                if(i == j) { continue; }
                if(nums[j] == target) { target_count += 1; }
                if(target_count >= 2) { valid = true; break; }
            }
            if(valid) { used_nums.push_back(num); output.push_back({num, target, target}); }
        }


        // 2. Find cases with no duplicates
        // merge sort, remove duplicates
        vector<int> sorted = merge_sort(nums);
        for(int i = 0; i < sorted.size() && sorted[i] < 0; i++) {
            int target = -1 * sorted[i];
            int left_idx = i + 1;
            int right_idx = sorted.size() - 1;

            while(left_idx < right_idx) {
                int sum = sorted[left_idx] + sorted[right_idx];
                if(sum == target) { 
                    vector<int> temp = {sorted[i], sorted[left_idx], sorted[right_idx]};
                    output.push_back(temp);
                }
                if(sum < target) {
                    left_idx += 1;
                }
                else {
                    right_idx -= 1;
                }
            }
        }

        return output;
    }
};
