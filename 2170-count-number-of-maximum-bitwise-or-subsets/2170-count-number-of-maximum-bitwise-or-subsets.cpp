class Solution {
public:
    int countSubsets(int idx, int currOr, int mxOr, vector<int>&nums, vector<vector<int>>&mem){
        if(idx==nums.size()){
            if(currOr==mxOr) return 1;
            else return 0;
        }
        if(mem[idx][currOr] != -1) return mem[idx][currOr];

        int take = countSubsets(idx+1, currOr | nums[idx], mxOr, nums, mem);   // include nums
        int notTake = countSubsets(idx+1, currOr, mxOr, nums, mem);  // exclude nums
        return mem[idx][currOr] = take + notTake;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int mxOr = 0;
        for(auto &av:nums){
            mxOr |= av;
        }
        int n = nums.size();
        vector<vector<int>>mem(n+1, vector<int>(mxOr+1, -1));  // use memoization
        int currOr = 0;
        return countSubsets(0, currOr, mxOr, nums, mem);
    }
};