class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        int totsum = accumulate(nums.begin(), nums.end(), 0);
        int lsum = 0;
        for(int i=0; i<n; i++){
            int rsum = totsum-lsum-nums[i];
            ans[i] = abs(rsum-lsum);
            lsum += nums[i];
        }
        return ans;
    }
};

// arr[i] = leftsum (from 0 to i-1) - rightsum (i+1 to n)