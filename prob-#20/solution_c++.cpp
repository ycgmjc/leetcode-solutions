class Solution {
public:
    bool isValid(string s) {
        vector<char> check;
        check.push_back('b');
               
        for(char c : s) {
            if(c == '(' || c == '{' || c == '[') {
                check.push_back(c);
            }
            else if(c == ')') {
                if(check.back() == '(') { check.pop_back(); }
                else { return false; }
            }
            else if(c == '}') {
                if(check.back() == '{') { check.pop_back(); }
                else { return false; }
            }
            else if(c == ']') {
                if(check.back() == '[') { check.pop_back(); }
                else { return false; }
            }
        }
        
        if(check.size() == 1) { return true; }
        else { return false; }
    }
};
