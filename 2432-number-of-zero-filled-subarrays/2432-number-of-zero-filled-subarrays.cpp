class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long n = nums.size();
        long long ans = 0, cnt = 0;   // cnt for consecutive 0's
        for(int i=0; i<n; i++){
            if(nums[i]==0) cnt++;
            else cnt = 0;
            ans += cnt;
        }
        return ans;
    }
};