class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n<=2) return n;
        int mx = 2;   // straight line lies on at least 2 points
        // let, i=(x1,y1) -> (i0, i1); same as for j=(x2,y2)->(j0,j1) & k=(x3,y3)->(k0,k1)
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int cnt = 2;
                for(int k=0; k<n; k++){
                    if(k!=i and k!=j){
                        if((points[j][1]-points[i][1])*(points[k][0]-points[i][0])==(points[j][0]-points[i][0])*(points[k][1]-points[i][1])) cnt++;
                    }
                }
                mx = max(mx, cnt);
            }
        }
        return mx;
    }
};