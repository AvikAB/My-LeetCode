class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int tot = m*n;
        
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int idx = i*n+j;  // idx in 1d arr (before rotation)
                int newIdx = (idx+k) % tot;  // idx in 1d arr (after rotation)

                // 1d to 2d
                int newRow = newIdx/n;
                int newCol = newIdx%n;

                ans[newRow][newCol] = grid[i][j];
            }
        }
        return ans;
    }
};