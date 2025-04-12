class Solution {
public:
    #define ll long long
    bool isSafe(ll x, ll y, ll n, const vector<string>&board){
        // for column
        for(int i=0; i<x; i++){
            if(board[i][y]=='Q') return false;
        }
        // for upper-right diagonal
        ll i = x, j = y;
        while(i>=0 and j<n){
            if(board[i][j]=='Q') return false;
            i--;
            j++;
        }
        // for upper-left diagonal
        i = x, j = y;
        while(i>=0 and j>=0){
            if(board[i][j]=='Q') return false;
            i--;
            j--;
        }
        return true;
    }

    void nQueen(ll row, ll n, vector<string>&board, vector<vector<string>>&res){
        if(row==n){
            res.push_back(board);
            return;
        }
        for(int col=0; col<n; col++){  // row-wise column
            if(isSafe(row, col, n, board)){
                board[row][col] = 'Q';
                nQueen(row+1, n, board, res);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string> board(n, string(n,'.'));
        nQueen(0, n, board, res);
        return res;
    }
};