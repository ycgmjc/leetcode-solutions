class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int peak = 0;
        int prev = 0;
        for(int num : gain) {
            int location = prev + num;
            if(location > peak) { peak = location; }
            prev = location;
        }
        return peak;
    }
};
