class Solution {
public:
    vector<int> merge(vector<int>& num1, vector<int>& num2) {
        vector<int> merged;
        int idx1 = 0;
        int idx2 = 0;

        while(idx1 < num1.size() && idx2 < num2.size()) {
            if(num1[idx1] <= num2[idx2]) {
                merged.push_back(num1[idx1]);
                idx1 += 1;
            } 
            else {
                merged.push_back(num2[idx2]);
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

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sorted = merge_sort(nums);

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
