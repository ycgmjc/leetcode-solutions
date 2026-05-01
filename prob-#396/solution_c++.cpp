class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int best = 0;
        int n = nums.size();
        int sum = 0;

        for(int i = 0; i < n; i++) {
            best += i * nums[i];
            sum += nums[i];
        }

        int temp = best;
        for(int i = 1; i < n; i++) {
            temp = temp + sum - (n * nums[n - i]);

            if(temp > best) { best = temp; }
        }

        return best;
    }
};
