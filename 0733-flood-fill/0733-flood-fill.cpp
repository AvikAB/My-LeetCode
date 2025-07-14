class Solution {
public:
    void dfs(int i, int j, int iniCol, int newCol, vector<vector<int>>&image){
        int n = image.size();
        int m = image[0].size();  // num of columns
        if(i<0 or j<0) return;
        if(i>=n or j>=m) return;
        if(image[i][j] != iniCol) return;
        image[i][j] = newCol;
        dfs(i-1, j, iniCol, newCol, image);
        dfs(i+1, j, iniCol, newCol, image);
        dfs(i, j-1, iniCol, newCol, image);
        dfs(i, j+1, iniCol, newCol, image);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniCol = image[sr][sc];    // initial color will be main row's & colomn's color
        if(iniCol != color) dfs(sr, sc, iniCol, color, image);
        return image;
    }
};