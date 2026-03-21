class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int i=0; i<k/2; i++){
            int tRow = x+i;
            int bRow = x+(k-i-1);
            for(int col=0; col<k; col++){
                swap(grid[tRow][y+col], grid[bRow][y+col]);
            }
        }
        return grid;
    }
};