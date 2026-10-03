class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, mx = nums[0];
        for(auto av:nums){
            sum += av;
            mx = max(mx, sum);
            if(sum<0) sum = 0;
        }
        return mx;
    }
};

// Kadane's Algo