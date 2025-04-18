class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xr = 0;
        for(auto av:nums){
            xr ^= av;
        }
        return xr;
    }
};