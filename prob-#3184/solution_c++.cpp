class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int n = hours.size();
        int output = 0;

        for(int i = 0; i < n - 1; i++) {
            int i_num = hours[i];
            for(int j = i + 1; j < n; j++) {
                int j_num = hours[j];
                if((i_num + j_num) % 24 == 0) { output += 1; }
            }
        }

        return output;
    }
};
