class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        vector<int>v = nums;
        unordered_set<int> s (v.begin(), v.end());
        vector<int> w(s.begin(), s.end());
        sort(w.rbegin(), w.rend());
        vector<int>res;
        for(int i=0; i<min(k, (int)w.size()); i++){
            res.push_back(w[i]);
        }
        return res;
    }
};