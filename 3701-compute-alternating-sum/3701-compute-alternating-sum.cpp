class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int evnSum = 0, oddSum = 0;
        for(int i=0; i<nums.size(); i++){
            if(i%2) oddSum += nums[i];
            else evnSum += nums[i];
        }
        return evnSum-oddSum;
    }
};