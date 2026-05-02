class Solution {
public:
    int rotatedDigits(int n) {
        int output = 0;
        vector<int> digits;

        for(int i = 1; i < n + 1; i++) {
            int num = i;
            bool pass = false;
            digits.clear();
            
            while(num > 0) {
                if(num % 10 == 3 || num % 10 == 4 || num % 10 == 7) 
                { pass = true; break; }
                digits.push_back(num % 10);
                num /= 10;
            }
            if(pass) { continue; }

            for(int digit : digits) {
                if(digit == 2 || digit == 5 || digit == 6 || digit == 9) { output += 1; break; }
            }
        }

        return output;
    }
};
