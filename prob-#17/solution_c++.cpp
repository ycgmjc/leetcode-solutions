class Solution {
public:
    vector<vector<string>> dictionary = {
        {"a", "b", "c"},
        {"d", "e", "f"},
        {"g", "h", "i"},
        {"j", "k", "l"},
        {"m", "n", "o"},
        {"p", "q", "r", "s"},
        {"t", "u", "v"},
        {"w", "x", "y", "z"}
    };

    vector<string> add_digits(vector<string>& strings, vector<int>& digits, int idx) {
        if(idx >= digits.size()) { return strings; }

        vector<string> new_strings;
        for(string s : strings) {
            for(string to_add : dictionary[digits[idx]]) {
                new_strings.push_back(s + to_add);
            }
        }

        return add_digits(new_strings, digits, idx + 1);
    }

    vector<string> letterCombinations(string digits) {
        vector<int> input_digits;
        vector<string> output;
        

        for(char c : digits) {
            input_digits.push_back(c - '2');
        }

        for(int i = 0; i < dictionary[input_digits[0]].size(); i++) {
            output.push_back(dictionary[input_digits[0]][i]);
        }

        return add_digits(output, input_digits, 1);
    }
};
