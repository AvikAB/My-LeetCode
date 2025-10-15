class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n<=2) return n;
        int ans = 0;
        for(int i=0; i<n; i++){
            unordered_map<double,int>mp;  // {slope of the line, how many points has same slope}
            for(int j=0; j<n; j++){
                if(j==i) continue;
                auto dy = points[j][1]-points[i][1];  // y2-y1
                auto dx = points[j][0]-points[i][0];  // x2-x1
                auto theta = atan2(dy, dx);
                mp[theta]++;
            }
            for(auto &av:mp){
                ans = max(ans, av.second+1);  // av.second+1 for including i point
            }
        }
        return ans;
    }
};