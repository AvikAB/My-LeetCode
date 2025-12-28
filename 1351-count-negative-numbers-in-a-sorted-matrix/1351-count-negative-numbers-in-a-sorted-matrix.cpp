class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0;
        for(auto av:grid){
            reverse(av.begin(), av.end());
            int lb = lower_bound(av.begin(), av.end(), 0) - av.begin();
            res += lb;
        }
        return res;
    }
};