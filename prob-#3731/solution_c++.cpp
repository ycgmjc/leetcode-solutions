class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> output;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        int cur = nums[0];

        for(int i = 0; i < n; i++) {
            int num = nums[i];
            while(num > cur) {
                output.push_back(cur);
                cur += 1;
            }
            cur += 1;
        }
        return output;
    }
};
