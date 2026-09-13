class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> non_zero_pos1;  // 1's pos in img1
        vector<pair<int,int>> non_zero_pos2;  // 1's pos in img2
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(img1[i][j]==1) non_zero_pos1.push_back({i, j});
                if(img2[i][j]==1) non_zero_pos2.push_back({i, j});
            }
        }

        int ans = 0;
        map<pair<int,int>,int>mp;  // {{r2-r1, c2-c1}, cnt}
        for(auto [r1, c1]:non_zero_pos1){
            for(auto [r2, c2]:non_zero_pos2){
                mp[{r2-r1, c2-c1}]++;
                ans = max(ans, mp[{r2-r1, c2-c1}]);
            }
        }
        return ans;
    }
};



/*
{r2-r1, c2-c1} gives how many moves needed to shift and track it on map, and ans will give the max cnt of overlap.
*/