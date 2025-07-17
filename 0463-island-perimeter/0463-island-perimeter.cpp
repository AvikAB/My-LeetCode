class Solution {
public:
    void dfs(int i, int j, int &peri, vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]==0){
            peri++;
            return;
        }
        if(grid[i][j]!=1) return;  // already visited & not land
        grid[i][j] = -1;  // mark visited
        dfs(i+1, j, peri, grid);
        dfs(i-1, j, peri, grid);
        dfs(i, j+1, peri, grid);
        dfs(i, j-1, peri, grid);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int peri = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    dfs(i,j,peri,grid);
                    return peri;
                }
            }
        }
        return -1;
    }
};