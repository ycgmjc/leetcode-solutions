class Solution {
public:
    int reverseBits(int n) {
        vector<int> binary(32);
        int index = 31;
        while(n > 0) {
            binary[index] = n % 2;
            n /= 2;
            index -= 1;
        }

        int output = 0;
        long long pow = 1;
        for(int digit : binary) {
            output += pow * digit;
            pow *= 2;
        }

        return output;
    }
};
