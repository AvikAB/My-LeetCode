// Using Memoization:
class Solution {
public:
    int solve(vector<int>&v, int i, int j, vector<vector<int>>&dp){
        if(i+1==j) return 0;  // base case
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        for(int k=i+1; k<j; k++){
            ans = min(ans, v[i]*v[j]*v[k] + solve(v,i,k,dp) + solve(v,k,j,dp));
        }
        return dp[i][j] = ans;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(values, 0, n-1, dp);
    }
};



// Using DP:
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        for(int len=2; len<n; len++){
            for(int i=0; i<n-len; i++){
                int j = i+len;
                dp[i][j] = INT_MAX;
                for(int k=i+1; k<j; k++){
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]+values[i]*values[j]*values[k]);
                }
            }
        }
        return dp[0][n-1];
    }
};
