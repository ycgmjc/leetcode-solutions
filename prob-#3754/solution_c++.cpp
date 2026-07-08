class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        string x_s = "";
        for(char c : s) {
            if(c == '0') { continue; }
            x_s += c;
        }
        if(x_s == "") { return 0; }
        long long x = (long long)stoi(x_s);
        int temp = x;
        int sum = 0;
        while(temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        return x * sum;
    }
};
