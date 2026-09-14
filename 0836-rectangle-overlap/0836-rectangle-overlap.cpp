class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0];
        int y1 = rec1[1];
        int x2 = rec1[2];
        int y2 = rec1[3];

        int x3 = rec2[0];
        int y3 = rec2[1];
        int x4 = rec2[2];
        int y4 = rec2[3];

        // x-axis overlap: (x1<x4) and (x3<x2) means x3 in the middle of x1 and x2
        // y-axis overlap: (y1<y4) and (y3<y2)

        return (x1<x4) and (x3<x2) and (y1<y4) and (y3<y2);
    }
};