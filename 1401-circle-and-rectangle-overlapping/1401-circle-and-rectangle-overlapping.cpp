class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int nearestX, nearestY;
        if(x1>xCenter) nearestX = x1;  // rect in right side of circle
        else if(x2<xCenter) nearestX = x2;   // rect in left side of circle
        else nearestX = xCenter;   // xCenter lied on the middle of the rect

        if(y1>yCenter) nearestY = y1;
        else if(y2<yCenter) nearestY = y2;
        else nearestY = yCenter;

        int dx = nearestX - xCenter;
        int dy = nearestY - yCenter;
        int dist = hypot(dx, dy);

        return dist <= radius;
    }
};


/*
Find the nearest point of rectangle from the circle. If their distance is less than or equal to the radius then its overlap, else not overlap.
*/