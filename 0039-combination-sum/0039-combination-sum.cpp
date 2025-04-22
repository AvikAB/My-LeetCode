class Solution {
public:
    set<vector<int>>st;
    vector<vector<int>>res;
    void combSum(int pos, int target, vector<int>&v, vector<int>&current){
        if(pos==v.size() or target<0) return;
        if(target==0){
            if(st.find(current)==st.end()){
                res.push_back(current);
                st.insert(current);
            }
            return;
        }
        current.push_back(v[pos]);
        combSum(pos+1, target-v[pos], v, current);  // single
        combSum(pos, target-v[pos], v, current);   // multiple
        current.pop_back();   //backtrack
        combSum(pos+1, target, v, current);  // exclude
    }

    vector<vector<int>> combinationSum(vector<int>&candidates, int target) {
        vector<int>current;
        combSum(0, target, candidates, current);
        return res;
    }
};