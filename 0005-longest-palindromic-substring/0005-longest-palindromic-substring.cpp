class Solution {
public:
    // Top Down DP
    int dp[1001][1001];
    // bool isPalin(string &s, int l, int r){
    //     while(l<r){
    //         if(s[l]!=s[r]) return false;
    //         l++;
    //         r--;
    //     }
    //     return true;
    // }

    bool solve(string &s, int l, int r){
        if(l>=r) return 1;

        if(dp[l][r]!=-1) return dp[l][r];

        if(s[l]==s[r]) return dp[l][r] = solve(s, l+1, r-1);
        
        return dp[l][r] = false;

    }

    string longestPalindrome(string s) {
        int n = s.size();
        int bestStart = 0, mxLen = 0;
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(solve(s, i, j)){
                    if(j-i+1>mxLen){
                        mxLen = j-i+1;
                        bestStart = i;
                    }
                }
            }
        }
    
        return s.substr(bestStart, mxLen);
    }
};