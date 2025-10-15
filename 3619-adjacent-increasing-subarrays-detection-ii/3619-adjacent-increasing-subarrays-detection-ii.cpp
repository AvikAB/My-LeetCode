class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, vector<int>&inc, int k) {
        int n = nums.size();
        if(n<2*k) return false;
        if(k==1) return true;   //1 ele is always true for every ops
        for(int i=0; i<=n-2*k; i++){  // I need 2 subarrs of k len, thats why n-2*k
            if(inc[i]>=k and inc[i+k]>=k) return true;
        }
        return false;
    }

    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> inc(n);  // pre computation of increasing
        inc[n-1] = 1;
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]) inc[i] = inc[i+1]+1;
            else inc[i] = 1;
        }
        int lo=1, hi=n/2;
        int ans = 0;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(hasIncreasingSubarrays(nums, inc, mid)){
                ans = mid;
                lo = mid+1;
            } else hi = mid-1;
        }
        return ans;
    }
};