class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> answer;
        for(int i = digits.size() - 1; i >= 0; i--) {
            int num = digits[i] + 1;
            if(num < 10) {
                digits[i] = num;
                break;
            }
            if(i == 0) {
                answer.push_back(1);
            }
            digits[i] = 0;
        }

        for(int digit : digits) {
            answer.push_back(digit);
        }
        return answer;
    }
};
