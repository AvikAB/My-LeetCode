class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int H = matrix.size();
        if(H==0) return 0;
        int W = matrix[0].size();
        vector<vector<int>> dp(H, vector<int>(W));
        int ans = 0;
        for(int row=H-1; row>=0; row--){
            for(int col=W-1; col>=0; col--){
                if(matrix[row][col]=='1'){
                    dp[row][col] = 1;
                    if(row!=H-1 and col!=W-1){
                        dp[row][col] += min({dp[row+1][col], dp[row][col+1], dp[row+1][col+1]});
                    }
                    ans = max(ans, dp[row][col]);
                }
            }
        }
        return ans*ans;
    }
};


/*
This is traversal from top-left (0,0) to right (R, C+1), down (R+1, C) and Diagonal (R+1, C+1).
*/