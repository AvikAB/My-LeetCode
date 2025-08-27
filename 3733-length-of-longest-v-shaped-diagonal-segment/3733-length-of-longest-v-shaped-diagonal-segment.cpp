class Solution {
public:
    int m,n;
    int memo[501][501][4][2];    // memoization for changeable varibles i,j,d(sz=4),2(true,false)

    vector<vector<int>> directions = {{1,1}, {1,-1}, {-1,-1}, {-1,1}};  // 90-deg directions
    
    int solve(int i, int j, int d, bool canTurn, int nxtVal, vector<vector<int>>&grid){
        int i_prime = i+directions[d][0];
        int j_prime = j+directions[d][1];
        if(i_prime<0 or i_prime>=m or j_prime<0 or j_prime>=n or grid[i_prime][j_prime]!=nxtVal){
            return 0;
        }
        if(memo[i_prime][j_prime][d][canTurn] != -1) return memo[i_prime][j_prime][d][canTurn];
        int res = 0;
        int keepMoving = 1+solve(i_prime, j_prime, d, canTurn, nxtVal == 2 ? 0:2, grid);
        res = max(res, keepMoving);

        if(canTurn==true){
            int turnAndMove = max(keepMoving, 1+solve(i_prime, j_prime, (d+1)%4, false, nxtVal == 2 ? 0:2, grid));
            res = max(res, turnAndMove);
        }
        return memo[i_prime][j_prime][d][canTurn] = res;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(memo, -1, sizeof(memo));
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    for(int d=0; d<=3; d++){   // for traverse directions
                        ans = max(ans, 1+solve(i, j, d, true, 2, grid));
                    }
                }
            }
        }
        return ans;
    }
};