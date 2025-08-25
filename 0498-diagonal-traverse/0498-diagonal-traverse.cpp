class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        map<int, vector<int>>mp;
        vector<int>res;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        bool flip = true;
        for(auto av:mp){
            if(flip) reverse(av.second.begin(), av.second.end());
            for(auto &num:av.second){
                res.push_back(num);
            }
            flip = !flip;
        }
        return res;
    }
};