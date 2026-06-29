class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int result = 0;
        for(string pattern : patterns) {
            if(word.contains(pattern)) {
                result += 1;
            }
        }
        return result;
    }
};
