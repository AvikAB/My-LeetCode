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