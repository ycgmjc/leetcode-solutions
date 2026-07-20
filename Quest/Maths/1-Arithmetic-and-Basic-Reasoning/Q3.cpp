class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) { return false; }
        if(x < 10) { return true; }
        if(x % 10 == 0) { return false; }
        
        vector<int> digits;
        long long reverse_x = 0;
        int temp_x = x;
        while(temp_x > 0) {
            digits.push_back(temp_x % 10);
            temp_x /= 10;
        }
        for(int i = 0; i < digits.size(); i++) {
            reverse_x *= 10;
            reverse_x += digits[i];
        }
        if(x == reverse_x) { return true; }
        else { return false; }
    }
};
