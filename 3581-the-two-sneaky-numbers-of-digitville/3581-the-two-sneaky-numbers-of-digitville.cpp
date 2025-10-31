class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        map<int,int>m;
        for(auto av:nums){
            m[av]++;
        }
        vector<int>res;
        for(auto &[val, freq]:m){
            if(freq==2) res.push_back(val);
        }
        return res;
    }
};