class Solution {
public:
    bool isValid(int row, int col, vector<vector<char>>&board, char d){
        for(int i=0; i<9; i++){
            if(board[i][col]==d) return false;   // check the same char as d in the col
            if(board[row][i]==d) return false;   // check the same char as d in the row
        }
        int start_i = row/3 * 3;
        int start_j = col/3 * 3;
        for(int k=0; k<3; k++){
            for(int l=0; l<3; l++){
                if(board[start_i+k][start_j+l]==d) return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>&board){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.'){
                    for(char d='1'; d<='9'; d++){
                        if(isValid(i, j, board, d)){
                            board[i][j] = d;    // put the val
                            if(solve(board)==true){   // explore
                                return true;
                            }
                            board[i][j] = '.';   // if this is false then again fill with '.'
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};