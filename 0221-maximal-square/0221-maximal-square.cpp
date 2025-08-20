class Solution {
public:
    int H,W;
    // Recursive Way - TopDown Approach
    int helper(int row, int col, vector<vector<char>>&matrix, vector<vector<int>>&memo){
        if(row>=H or col>=W) return 0;
        if(matrix[row][col]=='0') return 0;
        if(memo[row][col] != -1) return memo[row][col];
        int right = helper(row, col+1, matrix, memo);
        int down = helper(row+1, col, matrix, memo);
        int diagonal = helper(row+1, col+1, matrix, memo);
        return memo[row][col] = 1+min({right, down, diagonal});
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        H = matrix.size();
        if(H==0) return 0;
        W = matrix[0].size();
        vector<vector<int>> memo(H, vector<int>(W, -1));
        int ans = 0;
        for(int row=0; row<H; row++){
            for(int col=0; col<W; col++){
                ans = max(ans, helper(row, col, matrix, memo));
            }
        }
        return ans*ans;
    }
};