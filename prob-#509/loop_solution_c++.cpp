class Solution {
public:
    int fib(int n) {
        if(n <= 1) { return n; }

        int num0 = 0;
        int num1 = 1;
        int output = 0;

        for(int i = 0; i < n - 1; i++) {
            output = num0 + num1;
            num0 = num1;
            num1 = output;
        }

        return output;
    }
};
