class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total_time = 0;

        for (int i = 0; i < timeSeries.size() - 1; ++i) {
            total_time += std::min(duration, timeSeries[i + 1] - timeSeries[i]);
        }
        
        total_time += duration;
        
        return total_time;
    }
};
