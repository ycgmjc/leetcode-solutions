class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1) { return x; }
        if(x == -1) { return 1 - (n % 2) * 2; }
        if(n == -2147483648) { return 0; }

        long long _n = n;
        if(n < 0) { x = 1 / x; _n = -1 * (long long)n; }

        double answer = 1;
        for(long long i = 0; i < _n; i++) {
            answer *= x;
        }
        return answer;
    }
};
