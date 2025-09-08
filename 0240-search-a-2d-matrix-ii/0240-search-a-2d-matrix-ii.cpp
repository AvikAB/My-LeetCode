class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int rowIdx = 0;
        int colIdx = col-1;
        while(rowIdx<row and colIdx>=0){
            if(matrix[rowIdx][colIdx] == target) return true;
            else if(matrix[rowIdx][colIdx] > target) colIdx--;
            else rowIdx++;
        }
        return false;
    }
};



/*
Here, Each row is shorted left → right & each col is sorted top → bottom. So, moving left
makes values smaller & moving down makes values larger. 
Start from top-right corner, check it with their val, if target==val return true, else if val > target, move left (colIdx--), else if val < target, move down (rowIdx++).
*/