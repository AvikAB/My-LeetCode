class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        int total1 = 0, row = 0;
        for(int i=0; i<r; i++){   // row fixed
            int cnt1 = 0;
            for(int j=0; j<c; j++){  // col changeable
                if(mat[i][j]==1) cnt1++;
            }
            if(total1 < cnt1){
                row = i;
                total1 = cnt1;
            }
        }
        return {row, total1};
    }
};