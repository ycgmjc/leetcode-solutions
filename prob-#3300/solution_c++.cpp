class Solution {
public:
    int minElement(vector<int>& nums) {
        int answer = nums[0];
        for(int num : nums) {
            int digit_sum = 0;
            while(num > 0) {
                digit_sum += num % 10;
                num /= 10;
            }
            if(answer > digit_sum) { answer = digit_sum; }
        }
        return answer;
    }
};
