class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int cnt = 0;
        int tot = row*col;
        int startRow = 0;
        int startCol = 0;
        int endRow = row-1;
        int endCol = col-1;
        vector<int> ans;

        while(cnt < tot){
            // print starting row -> row fixed, col changeable
            for(int i=startCol; i<=endCol and (cnt<tot); i++){
                ans.push_back(matrix[startRow][i]);
                cnt++;
            }
            startRow++;
            // print ending col -> col fixed, row changeable
            for(int i=startRow; i<=endRow and (cnt<tot); i++){
                ans.push_back(matrix[i][endCol]);
                cnt++;
            }
            endCol--;
            // print last row -> row fixed, col changeable
            for(int i=endCol; i>=startCol and (cnt<tot); i--){
                ans.push_back(matrix[endRow][i]);
                cnt++;
            }
            endRow--;
            // print starting col -> col fixed, row changeable
            for(int i=endRow; i>=startRow and (cnt<tot); i--){
                ans.push_back(matrix[i][startCol]);
                cnt++;
            }
            startCol++;
        }
        return ans;
    }
};



/*
Just print the first row and count it, then print the last col & cnt it, then it won't be
the first and last row & col. After that print the last row & cnt it, then print the first
col and cnt it. If cnt < total then print that.

Spiral -> first row, last col, first+1 row, last-1 col & so on.

It means startRow, startCol always will be increment after their operation & endRow, endCol always will be in decrement after their operation.
*/