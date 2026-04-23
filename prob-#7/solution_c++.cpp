class Solution {
public:
    int reverse(int x) {
        int reversed_x = 0;
        int temp_x = x;
        bool is_negative = false;

        int max_val = 1;
        for(int i = 0; i < 31; i ++) {
            max_val *= 2;
            if(i == 29) { max_val -= 1; }
            if(i == 30) { max_val += 1; }
        }

        int min_val = -1 * max_val - 1;

        vector<int> reversed_digits;

        if(x < 0 && x > min_val) {
            is_negative = true;
            temp_x = temp_x * -1;
        }
        else if(x < 0) { return 0; }

        while(temp_x > 0) {
            reversed_digits.push_back(temp_x - ((temp_x / 10) * 10));
            temp_x /= 10;
        }

        for(int digit : reversed_digits) {
            if(reversed_x >= max_val / 10 + 1) { return 0; }
            reversed_x *= 10;
            reversed_x += digit;
        }

        if(is_negative) { reversed_x *= -1; }

        return reversed_x;
    }
};
