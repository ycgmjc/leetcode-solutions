class Solution {
public:
    int substitution(string word1, string word2, int i, int j) {
        int result = 1;
        if(word1[i - 1] == word2[j - 1]) { result = 0; }
        return result;
    }

    int minDistance(string word1, string word2) {
        int len1 = word1.length() + 1;
        int len2 = word2.length() + 1;
        vector<vector<int>> distance(len1, vector<int>(len2, INT_MAX));
        for(int i = 0; i < len1; i++) {
            distance[i][0] = i;
        }
        for(int i = 0; i < len2; i++) {
            distance[0][i] = i;
        }
        distance[0][0] = 0;
        for(int i = 1; i < len1; i++) {
            for(int j = 1; j < len2; j++) {
                distance[i][j] = min({distance[i - 1][j] + 1,
                                    distance[i][j - 1] + 1,
                                    distance[i - 1][j - 1] + substitution(word1, word2, i, j)});
            }
        }
        return distance[len1 - 1][len2 - 1];
    }
};
