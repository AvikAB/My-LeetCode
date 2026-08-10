class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool>dp(n+1, false);
        for(int i=1; i<=n; i++){
            for(int j=1; j*j<=i; j++){
                // try removing perfect sqr (j*j)<=i
                //if dp[i-j*j] is false, opponent loses after this move, so dp[i]=true
                if(!dp[i-j*j]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};