class Solution {
public:
    int minArea(int startRow, int endRow, int startCol, int endCol, vector<vector<int>>&grid){
        int m = grid.size();    // row
        int n = grid[0].size();   // col
        int mnRow = m, mxRow = -1;
        int mnCol = n, mxCol = -1;

        for(int i=startRow; i<endRow; i++){
            for(int j=startCol; j<endCol; j++){
                if(grid[i][j]==1){
                    mnRow = min(mnRow, i);
                    mxRow = max(mxRow, i);
                    mnCol = min(mnCol, j);
                    mxCol = max(mxCol, j);
                }
            }
        }
        return (mxRow-mnRow+1) * (mxCol-mnCol+1);
    }

    int minimumSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = INT_MAX;
        for(int rowSplit=1; rowSplit<m; rowSplit++){      // row and col can't split at 0
            for(int colSplit=1; colSplit<n; colSplit++){
                // case 1:
                int top = minArea(0, rowSplit, 0, n, grid);
                int bottomLeft = minArea(rowSplit, m, 0, colSplit, grid);
                int bottomRight = minArea(rowSplit, m, colSplit, n, grid);
                res = min(res, top+bottomLeft+bottomRight);

                // case 2:
                int topLeft = minArea(0, rowSplit, 0, colSplit, grid);
                int topRight = minArea(0, rowSplit, colSplit, n, grid);
                int bottom = minArea(rowSplit, m, 0, n, grid);
                res = min(res, topLeft+topRight+bottom);
            }
        }
        // case 3: all 2 splits in horizontal
        for(int split1=1; split1<m; split1++){
            for(int split2=split1+1; split2<m; split2++){
                int top = minArea(0, split1, 0, n, grid);
                int middle = minArea(split1, split2, 0, n, grid);
                int bottom = minArea(split2, m, 0, n, grid);
                res = min(res, top+middle+bottom);
            }
        }
        //case 4: all 2 splits in vertical
        for(int split1=1; split1<n; split1++){
            for(int split2=split1+1; split2<n; split2++){
                int left = minArea(0, m, 0, split1, grid);
                int middle = minArea(0, m, split1, split2, grid);
                int right = minArea(0, m, split2, n, grid);
                res = min(res, left+middle+right);
            }
        }
        
        for(int rowSplit=1; rowSplit<m; rowSplit++){
            for(int colSplit=1; colSplit<n; colSplit++){
                // case 5: Rotated of case 1
                int topLeft = minArea(0, rowSplit, 0, colSplit, grid);
                int bottomLeft = minArea(rowSplit, m, 0, colSplit, grid);
                int right = minArea(0, m, colSplit, n, grid);
                res = min(res, topLeft+bottomLeft+right);

                // case 6: Rotated of case 2
                int left = minArea(0, m, 0, colSplit, grid);
                int topRight = minArea(0, rowSplit, colSplit, n, grid);
                int bottomRight = minArea(rowSplit, m, colSplit, n, grid);
                res = min(res, left+topRight+bottomRight);
            }
        }

        return res;
    }
};