class Solution {
public:
    vector<vector<int>>res;
    void comb(int n, int pos, int k, vector<int>&current){
        if(current.size()==k){
            res.push_back(current);
            return;
        }
        if(pos>n) return;
        current.push_back(pos);   // include
        comb(n, pos+1, k, current);
        current.pop_back();       // exclude
        comb(n, pos+1, k, current);
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int>current;
        res.clear();
        comb(n, 1, k, current);
        return res;
    }
};