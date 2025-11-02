class Solution {
public:
    void markGuards(int row, int col, vector<vector<int>>&grid){
        // up side:
        for(int i=row-1; i>=0; i--){   // here, col fixed
            if(grid[i][col]==2 or grid[i][col]==3) break;
            grid[i][col] = 1;  // if not making it as guarded
        }
        // down side:
        for(int i=row+1; i<grid.size(); i++){   // here, col fixed
            if(grid[i][col]==2 or grid[i][col]==3) break;
            grid[i][col] = 1;
        }
        // left side:
        for(int j=col-1; j>=0; j--){   // here, row is fixed
            if(grid[row][j]==2 or grid[row][j]==3) break;
            grid[row][j] = 1;
        }
        // right side:
        for(int j=col+1; j<grid[0].size(); j++){   // here, row is fixed
            if(grid[row][j]==2 or grid[row][j]==3) break;
            grid[row][j] = 1;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>grid(m, vector<int>(n,0));
        // mark guards position as 2
        for(vector<int>&v : guards){
            int i = v[0];
            int j = v[1];
            grid[i][j] = 2;
        }

        // mark walls position as 3
        for(vector<int>&v : walls){
            int i = v[0];
            int j = v[1];
            grid[i][j] = 3;
        }

        for(vector<int>&guard : guards){
            int i = guard[0];
            int j = guard[1];
            markGuards(i, j, grid);   // check in the 4-directions & mark it as guarded if possible
        }

        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0) cnt++;
            }
        }
        return cnt;
    }
};