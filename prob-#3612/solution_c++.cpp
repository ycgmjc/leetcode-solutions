class Solution {
public:
    string processStr(string s) {
        string result = "";
        for(char c : s) {
            if(c - 'a' < 26 && c - 'a' >= 0) {
                result += c;
            }
            else if(c == '#') {
                result += result;
            }
            else if(c == '%') {
                string temp = "";
                for(int i = result.length() - 1; i >= 0; i--) {
                    temp += result[i];
                }
                result = temp;
            }
            else if(c == '*') {
                if(result == "") { continue; }
                result.pop_back();
            }
        }

        return result;
    }
};
