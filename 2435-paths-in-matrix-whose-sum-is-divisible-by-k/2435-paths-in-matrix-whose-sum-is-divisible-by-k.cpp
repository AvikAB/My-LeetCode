class Solution {
public:
    int m, n;
    int MOD = 1e9+7;
    int solve(int r, int c, int currSum, vector<vector<int>>&grid, int k, vector<vector<vector<int>>>&memo){
        if(r>=m or c>=n) return 0;
        if(r==m-1 and c==n-1) return (currSum+grid[r][c])%k == 0;   // base case

        if(memo[r][c][currSum] != -1) return memo[r][c][currSum];

        int down = solve(r+1, c, (currSum + grid[r][c])%k, grid, k, memo);
        int right = solve(r, c+1, (currSum + grid[r][c])%k, grid, k, memo);
        return memo[r][c][currSum] = (down+right)%MOD;   // total valid paths
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        // 3D because 3 states are changeable here (row, col, currSum%k)
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(k, -1)));
        return solve(0, 0, 0, grid, k, memo);
    }
};