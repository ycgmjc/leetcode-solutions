class Solution {
public:
    stack<int> slice_digits(int num) {
        stack<int> digits;
        while(num > 0) {
            digits.push(num % 10);
            num /= 10;
        }
        return digits;
    }

    int totalWaviness(int num1, int num2) {
        if(num2 <= 100) { return 0; }

        int output = 0;
        for(int i = num1; i <= num2; i++) {
            stack<int> digits = slice_digits(i);
            int n = digits.size();
            if(n < 3) { continue; }
            int prev = digits.top();
            digits.pop();
            while(true) {
                int num = digits.top();
                digits.pop();
                if(digits.empty()) { break; }
                int next = digits.top();
                if(num > prev && num > next) { output += 1; }
                else if(num < prev && num < next) { output += 1;}
                prev = num;
            }
        }
        return output;
    }
};
