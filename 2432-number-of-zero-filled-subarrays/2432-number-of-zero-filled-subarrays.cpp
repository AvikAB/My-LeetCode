class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long n = nums.size();
        long long ans = 0, cnt = 0;   // cnt for consecutive 0's
        for(int i=0; i<n; i++){
            if(nums[i]==0) cnt++;
            else{
                ans += (1LL*cnt*(cnt+1))/2;
                cnt = 0;
            }
        }
        if(cnt>0) ans += (1LL*cnt*(cnt+1))/2;  // handle the case if array ends with 0s
        return ans;
    }
};


/*
Intuition: Count consecutive zeroes and do N*(N+1)/2 and add them all.
*/