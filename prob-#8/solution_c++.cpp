class Solution {
public:
    int myAtoi(string s) {
        bool leading_zero = true;
        bool is_negative = false;
        bool start_string = false;
        int output = 0;

        int max_val = 1;
        for(int i = 0; i < 31; i ++) {
            max_val *= 2;
            if(i == 29) { max_val -= 1; }
            if(i == 30) { max_val += 1; }
        }

        int min_val = -1 * max_val - 1;

        for(char c : s) {
            if(c >= 49 && c <= 57 ) { 
                start_string = true;
                leading_zero = false; 
                
                if(output > max_val / 10 || (output == max_val / 10 && (c - 48) > 7)) 
                { 
                    if(is_negative) { return min_val; }
                    else { return max_val; } 
                }

                output *= 10; 
                output += (c - 48); 
            }
            else if(start_string == false && c == '-') { 
                start_string = true; 
                is_negative = true; 
            }
            else if(start_string == false && c == '+') { start_string = true; }
            else if(c == 48 && leading_zero == false) { 
                if(output > max_val / 10 || (output == max_val / 10 && (c - 48) > 7))
                { 
                    if(is_negative) { return min_val; }
                    else { return max_val; } 
                }
                output *= 10; 
                output += (c - 48); 
            }
            else if(c == 48) { start_string = true; }
            else if(start_string == false && c == 32) { continue; }
            else if(c < 48 || c > 57) { break; }
        }

        if(is_negative) { output *= -1; }

        return output;
    }
};
