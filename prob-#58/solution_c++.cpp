class Solution {
public:
    int lengthOfLastWord(string s) {
        bool word_started = false;
        int result = 0;
        for(int i = s.length() - 1; i >= 0; i--) {
            if(word_started == false && s[i] == ' ') { continue; }
            if(word_started == true && s[i] == ' ') { break; }
            word_started = true;
            result += 1;
        }
        return result;
    }
};
