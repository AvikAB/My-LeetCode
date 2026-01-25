class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int mn = INT_MAX;
        for(int i=k-1; i<nums.size(); i++){
            int mxEle = nums[i];
            int mnEle = nums[i-k+1];
            mn = min(mn, mxEle-mnEle);
        }
        return mn;
    }
};