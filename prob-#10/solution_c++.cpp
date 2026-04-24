class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) { return s.empty(); }

        bool head_match = (!s.empty() && (s[0] == p[0] || p[0] == '.'));
        if (p.length() >= 2 && p[1] == '*') {
            return (isMatch(s, p.substr(2)) 
                || (head_match && isMatch(s.substr(1), p)));
        } 
        else {
            return head_match && isMatch(s.substr(1), p.substr(1));
        }
    }
};
