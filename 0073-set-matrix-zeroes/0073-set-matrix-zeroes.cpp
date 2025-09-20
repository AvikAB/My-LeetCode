class Solution {
public:
    // Optimal: O(r*c)
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        bool firstRowImpact = false;
        bool firstColImpact = false;

        // check first row Impacted or not (any val of first col is 0 or not)
        for(int col=0; col<c; col++){
            if(matrix[0][col]==0){   // row fixed, col changeable
                firstRowImpact = true;
                break;
            }
        }

        // check first col impacted or not (any val of first col is 0 or not)
        for(int row=0; row<r; row++){
            if(matrix[row][0]==0){      // col fixed, row changeable
                firstColImpact = true;
                break;
            }
        }

        // set the first row/col is 0 if mat[i][j]=0, excluding the first row & first col
        for(int i=1; i<r; i++){
            for(int j=1; j<c; j++){
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;   // first ele of ith row
                    matrix[0][j] = 0;   // first ele of jth col
                }
            }
        }

        for(int i=1; i<r; i++){
            for(int j=1; j<c; j++){
                if(matrix[i][0]==0 or matrix[0][j]==0) matrix[i][j] = 0;
            }
        }

        // Now work with first row and first col, which was excluding
        // if 1st row ele is impacted then that row is 0, row fixed, col changeable
        if(firstRowImpact){
            for(int j=0; j<c; j++){  // col changeable thats why j runs for c
                matrix[0][j] = 0;
            }
        }

        // if 1st col ele is impacted then that col is 0, col fixed, row changeable
        if(firstColImpact){
            for(int i=0; i<r; i++){   // row changeable thats why i runs for r
                matrix[i][0] = 0;
            }
        }
    }
};




/*
If [i][j] = 0 then always impact by the first row element and first column element. 
    First row ele -> [i][0], First col ele -> [0][j].
then always do first ele of ith row [i][0] = 0 & first ele of jth col [0][j] = 0.

Then start traversal from 2nd row (1) and 2nd col (1). It means always avoid 1st row (0) &
1st col (0). Its the most important corner case for this problem. The avoided 1st row and 1st col will traverse later.

Each and every traversal it will check first row ele & first col ele, if any of they are 0 then it will be 0.
*/