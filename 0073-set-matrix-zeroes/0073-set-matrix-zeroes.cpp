class Solution {
public:
    // Bruteforce: O(r*c * (r+c))
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>>temp = matrix;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(matrix[i][j]==0){
                    for(int k=0; k<c; k++){   // k for cols, row fixed here & cols are changeable
                        temp[i][k] = 0;      // marking ith row as 0, that row's all val will be 0
                    }
                    for(int k=0; k<r; k++){   // k for rows, col fixed here & rows are changeable
                        temp[k][j] = 0;      // marking ith col as 0, that col's all val will be 0
                    }
                }
            }
        }
        matrix = temp;
    }
};