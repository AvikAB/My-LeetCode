class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, mx = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            mx = max(mx, sum);
            if(sum<0) sum = 0;
        }
        return mx;
    }
};