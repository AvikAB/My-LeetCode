class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int H = matrix.size();
        int W = matrix[0].size();
        if(H==0) return 0;
        vector<vector<int>> dp(H, vector<int>(W));
        int res = 0;

        // iterative way - (Bottom-up)
        for(int row=0; row<H; row++){
            for(int col=0; col<W; col++){
                if(matrix[row][col]==1){
                    if(row==0 or col==0) dp[row][col] = 1;
                    else dp[row][col] = 1+min({dp[row][col-1], dp[row-1][col], dp[row-1][col-1]});
                    res += dp[row][col];
                }
            }
        }
        return res;
    }
};


// Recursive Way:
class Solution {
public:
    int H,W;
    // Recursive Way - (Top-Down)
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& memo){
        if(i>=H or j>=W) return 0;
        if(matrix[i][j]==0) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        int right = solve(i, j+1, matrix, memo);
        int bottom = solve(i+1, j, matrix, memo);
        int diagonal = solve(i+1, j+1, matrix, memo);
        return memo[i][j] = 1 + min({right, bottom, diagonal});
    }

    int countSquares(vector<vector<int>>& matrix) {
        H = matrix.size();
        W = matrix[0].size();
        int res = 0;
        vector<vector<int>> memo(H+1, vector<int>(W+1, -1));
        for(int i=0; i<H; i++){  // row
            for(int j=0; j<W; j++){  // col
                if(matrix[i][j]==1) res += solve(i, j, matrix, memo);
            }
        }
        return res;
    }
};
