class Solution {
public:
    int climbStairs(int n) {
        int num = 0;
        int output = 1;

        for(int i = 0; i < n; i++) {
            output += num;
            num = output - num;
        }

        return output;
    }
};
