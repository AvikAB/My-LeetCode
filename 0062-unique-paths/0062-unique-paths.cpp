class Solution {
public:
    int nCr(int n, int r){
        long long int ans = 1;
        for(int i=1; i<=min(r,n-r); i++){
            ans = (ans*(n-i+1))/i;
        }
        return ans;
    }

    int uniquePaths(int m, int n) {
        return nCr(n+m-2, m-1);
    }
};