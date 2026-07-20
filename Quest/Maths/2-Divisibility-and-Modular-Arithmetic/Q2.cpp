class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k % 2 == 0 || k % 5 == 0) { return -1; }
        int output = 0;
        int num = 0;
        for (int output = 1; output <= k; ++output) {
            num = (num * 10 + 1) % k;
            if (num == 0) { return output; }
        }
        
        return -1;
    }
};
