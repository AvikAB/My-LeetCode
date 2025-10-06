class Solution {
public:
    vector<vector<int>> directions{{1,0}, {-1,0}, {0,1}, {0,-1}};
    int n;

    // DFS
    bool isPos(int mid, int i, int j, vector<vector<int>>&grid, vector<vector<bool>>&visited){
        if(i<0 or i>=n or j<0 or j>=n or grid[i][j]>mid or visited[i][j]==true){
            return false;
        }
        if(i==n-1 and j==n-1) return true;
        visited[i][j] = true;
        for(auto &dir : directions){
            int iprime = i+dir[0];
            int jprime = j+dir[1];
            if(isPos(mid, iprime, jprime, grid, visited)) return true;
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int l = grid[0][0], r = n*n-1;
        int ans = 0;
        while(l<=r){
            int mid = l+(r-l)/2;
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            if(isPos(mid, 0, 0, grid, visited)){
                ans = mid;
                r = mid-1;
            } else l = mid+1;
        }
        return ans;
    }
};