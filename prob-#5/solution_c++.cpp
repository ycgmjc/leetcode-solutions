class Solution {
public:
    string longestPalindrome(string s) {
        int best_length = 0;
        string output;

        for(int i = 0; i < s.length(); i++) {
            char start = s[i];
            
            for(int j = i + 1; j < s.length(); j++) {
                int head_idx = i;
                int tail_idx = j;
                bool success = true;
                if(s[j] == s[i]) {
                    while(head_idx < tail_idx) {
                        head_idx += 1;
                        tail_idx -= 1;
                        if(s[head_idx] != s[tail_idx]) { success = false; break; }
                    }

                    if(success && (j - i + 1 > best_length)) {
                        best_length = j - i + 1;
                        output = s.substr(i, j - i + 1);
                    }
                }
            }
        }

        if(best_length == 0) { best_length = 1; output = s[0]; }

        return output;
    }
};
