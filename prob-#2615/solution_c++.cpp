class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int length = nums.size();
        vector<long long> output(length);

        // <num, all idx where nums[idx] = num>
        unordered_map<int, vector<int>> indices;

        // construct
        for(int i = 0; i < length; i++) {
            indices[nums[i]].push_back(i);
        }
        
        for (const auto& [num, offsets] : indices) {
            long long sum = 0;
            for (int idx : offsets) {
                sum += idx;
            }

            long long left_sum = 0;
            long long right_sum = sum;

            for (int i = 0; i < offsets.size(); i++) {
                long long curr_idx = offsets[i];
                
                right_sum -= curr_idx;
                
                long long left_count = i;
                long long right_count = offsets.size() - 1 - i;

                // apply math formula
                long long left_distance = (left_count * curr_idx) - left_sum;
                long long right_distance = right_sum - (right_count * curr_idx);
                
                output[curr_idx] = left_distance + right_distance;

                left_sum += curr_idx;
            }
        }

        return output;
    }
};
