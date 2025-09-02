class Solution {
public:
    static bool cmp(const vector<int>&p, const vector<int>&q){
        if(p[0]==q[0]) return p[1]<q[1];   // if x1,x2 are equal then print the larger (y1 or y2) first, then (y1 or y2) second
        else return p[0]>q[0];   // otherwise, smaller x before the larger x
    }

    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        sort(points.begin(), points.end(), cmp);
        for(int i=0; i<n-1; i++){
            int y = INT_MAX;
            for(int j=i+1; j<n; j++){
                if(points[j][1] >= points[i][1] and y>points[j][1]){
                    ans++;
                    y = points[j][1];
                }
            }
        }
        return ans;
    }
};