class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        vector<unordered_set<char>> rows(n), cols(n), boxes(n);
        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                char cell = board[r][c];
                if(cell=='.') continue;
                if(rows[r].count(cell)) return false;  // present there
                rows[r].insert(cell);    // if not present, then add the val there

                if(cols[c].count(cell)) return false;
                cols[c].insert(cell);

                int boxIdx = 3*(r/3)+(c/3);
                if(boxes[boxIdx].count(cell)) return false;
                boxes[boxIdx].insert(cell);
            }
        }
        return true;
    }
};