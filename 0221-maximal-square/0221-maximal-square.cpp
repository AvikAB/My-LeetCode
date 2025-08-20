class Solution {
public:
    int H,W;
    // Recursive Way - TopDown Approach
    int helper(int row, int col, vector<vector<char>>&matrix, vector<vector<int>>&memo){
        if(row>=H or col>=W) return 0;
        if(matrix[row][col]=='0') return 0;
        if(memo[row][col] != -1) return memo[row][col];
        int right = helper(row, col+1, matrix, memo);
        int down = helper(row+1, col, matrix, memo);
        int diagonal = helper(row+1, col+1, matrix, memo);
        return memo[row][col] = 1+min({right, down, diagonal});
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        H = matrix.size();
        if(H==0) return 0;
        W = matrix[0].size();
        vector<vector<int>> memo(H, vector<int>(W, -1));
        int ans = 0;
        for(int row=0; row<H; row++){
            for(int col=0; col<W; col++){
                ans = max(ans, helper(row, col, matrix, memo));
            }
        }
        return ans*ans;
    }
};



// Iterative Way - BottomUp Approach:
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


// This is - Left, Up, Diagonal:
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int H = matrix.size();
        if(H==0 and matrix[0].empty()) return 0;
        int W = matrix[0].size();
        vector<vector<int>> dp(H, vector<int>(W));
        int ans = 0;
        for(int row=0; row<H; row++){
            for(int col=0; col<W; col++){
                if(matrix[row][col]=='1'){
                    dp[row][col] = 1;
                    if(row>0 and col>0){
                        dp[row][col] += min({dp[row-1][col], dp[row][col-1], dp[row-1][col-1]});
                    }
                    ans = max(ans, dp[row][col]);
                }
            }
        }
        return ans*ans;
    }
};
