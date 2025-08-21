class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        // pre computation
        vector<vector<int>> pre(n, vector<int>(m));
        for(int row=0; row<n; row++){
            int cnt = 0;   // cnt for each row
            for(int col=m-1; col>=0; col--){
                if(mat[row][col]==1) cnt++;
                else cnt = 0;
                pre[row][col] = cnt;
            }
        }

        int ans = 0;
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                int x = INT_MAX;
                for(int k=row; k<n; k++){   // it will go each of the row including curr row, checking for vertical
                    x = min(x, pre[k][col]);  // it will check the consecutive 1 or sum of 1 (cnt) for submatrices using pre[][]
                    ans += x;
                }
            }
        }
        return ans;
    }
};