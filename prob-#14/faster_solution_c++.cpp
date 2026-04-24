class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1) {
            return strs[0];
        }

        string best = "";
        string standard = strs[0];
        int shortest_length = strs[0].length();

        for(string s : strs) {
            if(s.length() < shortest_length) { shortest_length = s.length(); }
        }

        for(int i = 0; i < shortest_length; i++) {
            if(standard[i] == strs[1][i]) { best += standard[i]; }
            else { break; }
        }

        for(int i = 2; i < strs.size(); i++) {
            string subject = strs[i];
            int length = best.length();
            string new_best = "";
            for(int j = 0; j < length; j++) {
                if(best[j] == subject[j]) { new_best += best[j]; }
                else { break; }
            }
            best = new_best;
            if(best == "") { break; }
        }

        return best;
    }
};
