class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if (dividend == INT_MAX && divisor == -1) {
            return INT_MIN + 1;
        }

        long long dd = dividend;
        long long dr = divisor;
        long long q = 0;
        bool negative = false;
        if(dd < 0) {
            dd = 0 - dd;
            negative = !negative;
        }
        if(dr < 0) {
            dr = 0 - dr;
            negative = !negative;
        }
        while(true) {
            dd -= dr;
            if(dd < 0) {
                break;
            }
            else {
                q += 1;
            }
        }
    
        if(negative) {
            return 0 - q;
        }
        else {
            return q;
        }
    }
};
