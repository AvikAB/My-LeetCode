class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int ans = 0;
        for(auto av:nums){
            if(av%2==0) ans |= av;
        }
        return ans;
    }
};