class Solution {
public:
    int numberOfSpecialChars(string word) {
        int answer = 0;
        vector<bool> lowercase(26, false);
        vector<bool> uppercase(26, false);
        // 0 : false, 1 : true, 2 : locked
        vector<int> is_special(26, 0);
        for(int i = 0; i < word.size(); i++) {
            bool upper = false;
            int code = word[i];
            if(code > 96) { code = word[i] - 'a'; }
            else { upper = true; code = word[i] - 'A'; }
            if(upper) { 
                uppercase[code] = true; 
                if(lowercase[code] == true && is_special[code] == 0) {
                    is_special[code] = 1;
                }
            }
            else { 
                if(uppercase[code] == true) {
                    is_special[code] = 2;
                }
                else {
                    lowercase[code] = true; 
                }
            }
        }
        for(int i = 0; i < 26; i++) {
            if(is_special[i] == 1) { answer += 1; }
        }
        return answer;
    }
};
