class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string output = "";
        for(string word : words) {
            int sum = 0;
            for(char c : word) {
                int weight = weights[c - 'a'];
                sum += weight;
            }
            int mod = sum % 26;
            char letter = 'z' - mod;
            output += letter;
        }
        return output;
    }
};
