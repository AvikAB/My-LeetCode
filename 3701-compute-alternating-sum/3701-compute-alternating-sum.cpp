class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int evnSum = 0, oddSum = 0;
        for(int i=0; i<nums.size(); i+=2){
            evnSum += nums[i];
        }
        for(int i=1; i<nums.size(); i+=2){
            oddSum += nums[i];
        }
        return evnSum-oddSum;
    }
};