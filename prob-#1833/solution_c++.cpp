class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int result = 0;
        int sum = 0;
        for(int i = 0; i < costs.size(); i++) {
            int temp = sum + costs[i];
            if(temp <= coins) {
                sum = temp;
                result += 1;
            }
            else {
                break;
            }
        }
        return result;
    }
};
