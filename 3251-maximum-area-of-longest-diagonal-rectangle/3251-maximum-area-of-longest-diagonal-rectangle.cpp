class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int mxArea = 0, mxDiag = 0;
        for(auto &av:dimensions){
            int wt = av[0];
            int len = av[1];
            int diag = (wt*wt)+(len*len);
            if(diag>mxDiag){
                mxDiag = diag;
                mxArea = 0;
            }
            if(diag==mxDiag) mxArea = max(mxArea, wt*len);  // if diag & mxDiag are equal then we can say that current wt, len gives the mxArea
        }
        return mxArea;
    }
};