class Solution {
public:
    int MOD = 1e9+7;
    int memo[301][301];
    int solve(int n, int val, int x){
        if(n==0) return 1;   // found 1 way
        if(n<0) return 0;
        int currPow = pow(val, x);
        if(currPow>n) return 0;
        if(memo[n][val] != -1) return memo[n][val];
        int take = solve(n-currPow, val+1, x);
        int skip = solve(n, val+1, x);
        return memo[n][val] = (take+skip)%MOD;
    }

    int numberOfWays(int n, int x) {
        memset(memo, -1, sizeof(memo));
        return solve(n, 1, x);
    }
};