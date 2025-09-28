class Solution {
public:
    #define ll long long
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return -1;
        vector<ll>pre(n);
        pre[0] = nums[0];
        for(int i=1; i<n; i++){
            pre[i] = pre[i-1]+nums[i];
        }
        vector<bool>lp(n, 0);
        lp[0] = 1;
        for(int i=1; i<n; i++){
            if(nums[i]>nums[i-1]) lp[i] = lp[i-1];
            else lp[i] = 0;
        }
        vector<bool>rp(n, 0);
        rp[n-1] = 1;
        for(int i=n-2; i>=0; i--){
            if(nums[i]>nums[i+1]) rp[i] = rp[i+1];
            else rp[i] = 0;
        }
        ll mndiff = LLONG_MAX;
        bool ok = false;
        for(int i=0; i<n-1; i++){
            if(lp[i] and rp[i+1]){
                ll lsum = pre[i];
                ll rsum = pre[n-1]-pre[i];
                ll diff = abs(rsum - lsum);
                mndiff = min(mndiff, diff);
                ok = true;
            }
        }
        if(!ok) return -1;
        return mndiff;
    }
};