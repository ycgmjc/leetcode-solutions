class Solution {
public:
    int findGCD(vector<int>& nums) {
        int num1 = nums[0];
        int num2 = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            if(num < num1) { num1 = num; }
            else if(num > num2) { num2 = num; }
        }
        return gcd(num1, num2);
    }
};
