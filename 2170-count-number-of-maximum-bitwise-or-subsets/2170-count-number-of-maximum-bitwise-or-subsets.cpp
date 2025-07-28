class Solution {
public:
    int countSubsets(int idx, int currOr, int mxOr, vector<int>&nums){
        if(idx==nums.size()){
            if(currOr==mxOr) return 1;
            else return 0;
        }
        int take = countSubsets(idx+1, currOr | nums[idx], mxOr, nums);   // include nums
        int notTake = countSubsets(idx+1, currOr, mxOr, nums);  // exclude nums
        return take + notTake;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int mxOr = 0;
        for(auto &av:nums){
            mxOr |= av;
        }
        int currOr = 0;
        return countSubsets(0, currOr, mxOr, nums);
    }
};