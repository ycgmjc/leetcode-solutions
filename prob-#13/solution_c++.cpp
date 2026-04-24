class Solution {
public:
    int romanToInt(string s) {
        int output = 0;
        int idx = 0;
        while(idx < s.length()) {
            char roman = s[idx];
            bool safe = idx < s.length() - 1;
            switch(roman) {
                case 'M':
                    output += 1000;
                    idx += 1;
                    break;
                case 'D':
                    output += 500;
                    idx += 1;
                    break;
                case 'C':
                    if(safe) {
                        if(s[idx + 1] == 'M') { output += 900; idx += 2; break;}
                        if(s[idx + 1] == 'D') { output += 400; idx += 2; break;}
                    }
                    output += 100;
                    idx += 1;
                    break;
                case 'L':
                    output += 50;
                    idx += 1;
                    break;
                case 'X':
                    if(safe) {
                        if(s[idx + 1] == 'C') { output += 90; idx += 2; break;}
                        if(s[idx + 1] == 'L') { output += 40; idx += 2; break;}
                    }
                    output += 10;
                    idx += 1;
                    break;
                case 'V':
                    output += 5;
                    idx += 1;
                    break;
                case 'I':
                    if(safe) {
                        if(s[idx + 1] == 'X') { output += 9; idx += 2; break;}
                        if(s[idx + 1] == 'V') { output += 4; idx += 2; break;}
                    }
                    output += 1;
                    idx += 1;
                    break;
            }
        }

        return output;
    }
};
