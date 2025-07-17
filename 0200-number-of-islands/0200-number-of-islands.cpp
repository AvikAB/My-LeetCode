class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>&grid){
        int n = grid.size();      // num of rows
        int m = grid[0].size();   // num of cols
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]!='1') return;
        grid[i][j] = '#';  //mark visited
        dfs(i+1, j, grid);
        dfs(i-1, j, grid);
        dfs(i, j+1, grid);
        dfs(i, j-1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid);
                    islands++;
                }
            }
        }
        return islands;
    }
};