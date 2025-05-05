class Solution {
public:
    int solve(int row, int col, vector<vector<int>>&dp){
        if(row==0 and col==0) return 1;   // base case
        if(row<0 or col<0 or row<col) return 0;   // invalid cases
        if(dp[row][col] != -1) return dp[row][col];
        int ans = solve(row-1, col, dp) + solve(row-1, col-1, dp);   // let check the val of pascal's triangle as a 2D array's ele, dp[r][c]=dp[r-1][c]+dp[r-1][c-1]
        return dp[row][col] = ans;
    }

    vector<int> getRow(int rowIndex) {
        vector<int>ans;
        vector<vector<int>>dp(rowIndex+1, vector<int>(rowIndex+1, -1));

        for(int colIndex = 0; colIndex<=rowIndex; colIndex++){
            int val = solve(rowIndex, colIndex, dp);
            ans.push_back(val);
        }
        return ans;
    }
};