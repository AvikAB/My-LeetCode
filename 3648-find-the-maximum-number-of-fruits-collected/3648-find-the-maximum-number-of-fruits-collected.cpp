class Solution {
private:
    int n;

    int child3(int row, int col, vector<vector<int>>&fruits){
        if(row<0 or col<0 or row>=n or col>=n) return 0;
        if(dp[row][col] != -1) return dp[row][col];
        int val = fruits[row][col];
        int res = 0;
        if(row==col) res = max(res, child3(row+1, col+1, fruits));
        else if(row-1==col) res = max({res, child3(row+1, col+1, fruits), child3(row, col+1, fruits)});
        else res = max({res, child3(row+1, col+1, fruits), child3(row, col+1, fruits), child3(row-1, col+1, fruits)});
        return dp[row][col] = val+res;
    }

    int child2(int row, int col, vector<vector<int>>&fruits){
        if(row<0 or col<0 or row>=n or col>=n) return 0;
        if(dp[row][col] != -1) return dp[row][col];
        int val = fruits[row][col];
        int res = 0;
        if(row==col) res = max(res, child2(row+1, col+1, fruits));
        else if(row==col-1) res = max({res, child2(row+1, col+1, fruits), child2(row+1, col, fruits)});
        else res = max({res, child2(row+1, col+1, fruits), child2(row+1, col, fruits), child2(row+1, col-1, fruits)});
        return dp[row][col] = val+res;
    }

public:
    vector<vector<int>>dp;
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();
        int total = 0;
        dp = vector<vector<int>> (n, vector<int>(n, -1));
        // child-1 will eat all diagonal fruits
        for(int i=0; i<n; i++){
            total += fruits[i][i];
            fruits[i][i] = 0;
        }
        // child-3
        total += child3(n-1, 0, fruits);
        //child-2
        total += child2(0, n-1, fruits);
        return total;
    }
};