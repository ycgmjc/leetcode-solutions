class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> output;
        for(int i = left; i <= right; i++) {
            bool zero = false;
            bool include = true;
            vector<int> digits;
            int temp = i;
            while(temp > 0) {
                if(temp % 10 == 0) { zero = true; break; }
                digits.push_back(temp % 10);
                temp /= 10;
            }
            if(zero) { continue; }
            for(int digit : digits) {
                if(i % digit != 0) { include = false; break; }
            }
            if(include) { output.push_back(i); }
        }
        return output;
    }
};
