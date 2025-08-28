class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, vector<int>>mp;  // (i-j) -> {diagonal eles}
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int diag = i-j;
                mp[diag].push_back(grid[i][j]);
            }
        }
        for(auto &av:mp){
            if(av.first>=0) sort(av.second.begin(), av.second.end()); // bottom-left
            else sort(av.second.rbegin(), av.second.rend());   // top-right
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int diag = i-j;
                grid[i][j] = mp[diag].back();
                mp[diag].pop_back();
            }
        }
        return grid;
    }
};








/*
The ques says that bottom-left will be descending & top-right will be ascending. So, here I doing asc in bottom-left and desc in top-right and then pick the val from right side which i doing in mp[diag].back(), then remove that ele.
*/