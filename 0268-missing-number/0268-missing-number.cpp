class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorsum = 0;
        for(int i=0; i<=nums.size(); i++){
            xorsum ^= i;
        }
        for(int i=0; i<nums.size(); i++){
            xorsum ^= nums[i];
        }
        return xorsum;
    }
};