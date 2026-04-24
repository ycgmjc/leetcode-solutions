class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string best = "";
        string standard = strs[0];
        int shortest_length = strs[0].length();

        for(string s : strs) {
            if(s.length() < shortest_length) { shortest_length = s.length(); }
        }

        int idx = 0;
        
        while(idx < shortest_length) {
            bool common = true;
            for(string s : strs) {
                if(standard[idx] != s[idx]) {
                    common = false;
                    break;
                }
            }
            if(common == false) { break; }
            best += standard[idx];
            idx += 1;
        }

        return best;
    }
};
