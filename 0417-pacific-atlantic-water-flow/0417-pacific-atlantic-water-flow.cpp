class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int rows, cols;
    bool isValid(int x, int y, int rows, int cols) {
        return x>=0 and y>=0 and x<rows and y<cols;
    }

    void dfs(int x, int y, vector<vector<int>>& heights, vector<vector<bool>>& vis) {
        vis[x][y] = true;
        for (int i=0; i<4; i++){
            int newX = x+dx[i];
            int newY = y+dy[i];
            if (isValid(newX, newY, rows, cols) and !vis[newX][newY] and heights[newX][newY]>=heights[x][y]){
                dfs(newX, newY, heights, vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        // DFS from Pacific and Atlantic borders
        for(int i=0; i<rows; i++){
            dfs(i, 0, heights, pacific);          // Pacific (left)
            dfs(i, cols-1, heights, atlantic);  // Atlantic (right)
        }

        for(int j=0; j<cols; j++){
            dfs(0, j, heights, pacific);          // Pacific (top)
            dfs(rows-1, j, heights, atlantic);  // Atlantic (bottom)
        }

        vector<vector<int>> result;
        for (int i=0; i<rows; i++){
            for (int j=0; j<cols; j++) {
                if(pacific[i][j] and atlantic[i][j]){
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};