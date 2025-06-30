class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int>um;
        for(auto av:nums){
            um[av]++;
        }
        int len = 0;
        for(auto &[key, val]:um){
            if(um.count(key+1)){
                len = max(len, val+um[key+1]);
            }
        }
        return len;
    }
};