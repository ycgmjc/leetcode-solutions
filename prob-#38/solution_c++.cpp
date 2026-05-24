class Solution {
public:
    string transform(string s) {
        int n = s.length();
        string output = "";
        for(int i = 0; i < n; i++) {
            char num = s[i];
            int repeat = 1;
            while(i < n - 1 && s[i] == s[i + 1]) {
                repeat += 1;
                i += 1;
            }
            output += to_string(repeat);
            output += num;
        }
        return output;
    }

    string countAndSay(int n) {
        
        string answer = "1";
        for(int i = 0; i < n - 1; i++) {
            answer = transform(answer);
        }
        return answer;
    }
};
