class Solution {
public:
    int rec(int pos, vector<int>&nums, int target, int sum){
        if(pos==nums.size()) return sum==target;   // if its finish to traverse then it will check sum==target with plus, minus and plus,minus together
        int plus = rec(pos+1, nums, target, sum+nums[pos]);
        int minus = rec(pos+1, nums, target, sum-nums[pos]);
        return plus+minus;   // it will return tot num of ways 

    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return rec(0, nums, target, 0);
    }
};