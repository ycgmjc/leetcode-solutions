class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int best = 0;

        for(int i = 0; i < s.length(); i++) {
            vector<char> found;
            found.push_back(s[i]);
            int offset = 1;
            bool exists = false;

            while(!exists && i + offset < s.length()) {
                for(char c : found) {
                    if(c == s[i + offset]) { exists = true; break; }
                }

                if(!exists) {
                    found.push_back(s[i + offset]);
                    offset += 1;
                }
            }

            best = max(best, offset);
        }

        return best;
    }
};
