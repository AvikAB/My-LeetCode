class Solution {
public:
    double angleClock(int hour, int minutes) {
        double mAngle = 6.0*minutes;
        double hrAngle = 30.0 * (hour % 12) + 0.5 * minutes;
        double diff = abs(mAngle - hrAngle);
        return min(diff, 360.0-diff);
    }
};