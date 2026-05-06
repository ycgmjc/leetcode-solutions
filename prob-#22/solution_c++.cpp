class Solution {
public:
    vector<string> output;

    void generate(string s, int n, int open) {
        if(s.length() >= 2 * n && open == 0) { output.push_back(s); }
        else if(s.length() >= 2 * n) return;

        if(open == 0) { generate(s + '(', n, open + 1); return; }
        if(open > 0) {
            generate(s + ')', n, open - 1);
            if(open < n) {
                generate(s + '(', n, open + 1);
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        generate("", n, 0);
        return output;
    }
};
