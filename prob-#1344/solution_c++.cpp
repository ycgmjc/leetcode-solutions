class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hour_angle;
        double min_angle;
        
        hour_angle = 30 * hour + 0.5 * minutes;
        min_angle = 6 * minutes;

        double sub = abs(min_angle - hour_angle);
        return min(360 - sub, sub);
    }
};
