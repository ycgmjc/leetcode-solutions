class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(), cost.rend());
        int n = cost.size();
        int idx = 0;
        int cost_sum = 0;

        while(idx < n) {
            cost_sum += cost[idx];
            idx += 1;
            if((idx + 1) % 3 == 0) {
                idx += 1;
            }
        }
        return cost_sum;
    }
};
