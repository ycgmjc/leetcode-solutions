class Solution {
public:
    string convert(string s, int numRows) {
        string output;
        vector<string> rows;
        int depth = 0;
        bool going_down = true;

        if (numRows == 1) {
            return s;
        }

        for(int i = 0; i < numRows; i++) { rows.push_back(""); }

        for(char c : s) {
            rows[depth] += c;

            if(depth == numRows - 1) { going_down = false; }
            else if(depth == 0) { going_down = true; }

            if(going_down) { depth += 1; }
            else { depth -= 1; }
        }

        for(const string& row : rows) {
            output += row;
        }

        return output;
    }
};
