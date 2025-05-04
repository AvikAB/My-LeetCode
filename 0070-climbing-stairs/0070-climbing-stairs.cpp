class Solution {
public:
    int dp[50];
    int steps(int pos){
        if(pos<=1) return 1;
        if(dp[pos] != -1) return dp[pos];
        return dp[pos] = steps(pos-1)+steps(pos-2);
    }

    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        if(n<=3) return n;
        else return steps(n);
    }
};