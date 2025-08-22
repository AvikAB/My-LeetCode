class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int H = grid.size();
        int W = grid[0].size();
        int mnRow = H, mxRow = 0;
        int mnCol = W, mxCol = 0;
        for(int row=0; row<H; row++){
            for(int col=0; col<W; col++){
                if(grid[row][col]==1){
                    mnRow = min(mnRow, row);
                    mxRow = max(mxRow, row);
                    mnCol = min(mnCol, col);
                    mxCol = max(mxCol, col);
                }
            }
        }
        return (mxRow-mnRow+1)*(mxCol-mnCol+1);
    }
};