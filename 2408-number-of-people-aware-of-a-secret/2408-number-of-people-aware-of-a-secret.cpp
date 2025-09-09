class Solution {
public:
    const int mod = 1e9+7;
    int solve(int day, int n, int delay, int forget, vector<int>&dp){
        if(day>=n) return 1;
        if(dp[day] != -1) return dp[day];
        int ans = 1;
        for(int i=day+delay; i<=min(day+forget, n); i++){   // i = current days
            if(i==day+forget){
                ans--;
                break;
            }
            ans += (solve(i, n, delay, forget, dp))%mod;
        }
        return dp[day] = ans;
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n+1, -1);
        return solve(1, n, delay, forget, dp);
    }
};