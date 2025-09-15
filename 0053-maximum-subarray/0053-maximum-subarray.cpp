class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ps(n+1, 0);
        for(int i=0; i<n; i++){
            ps[i+1] = ps[i]+nums[i];
        }
        int mxSum = INT_MIN;
        int mnSum = 0;
        for(int i=1; i<=n; i++){
            mxSum = max(mxSum, ps[i]-mnSum);
            mnSum = min(mnSum, ps[i]);
        }
        return mxSum;
    }
};



// Maximum Subarray Sum using Prefix Sum (O(n)) -> Max Prefix Sum - Min Prefix Sum