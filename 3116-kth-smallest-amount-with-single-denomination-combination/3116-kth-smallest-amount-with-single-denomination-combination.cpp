class Solution {
public:
    #define ll long long
    ll cntLessThanX(vector<int>&coins, ll x){
        ll n = coins.size();
        ll allones = (1<<n)-1;
        ll cnt = 0;  // cnt of vals <= x
        for(int mask=1; mask<=allones; mask++){
            ll setbitsLCM = 1;
            for(int j=0; j<n; j++){
                if(mask & (1<<j)) setbitsLCM = lcm(setbitsLCM, coins[j]);
            }
            if(__builtin_popcount(mask)&1) cnt += (x/setbitsLCM);
            else cnt -= (x/setbitsLCM);
        }
        return cnt;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        ll l=1, r=51*1e9;
        ll ans = 0;
        while(l<=r){
            ll mid = (l+r)/2;
            ll cnt = cntLessThanX(coins, mid);
            if(cnt<k) l = mid+1;
            else {
                ans = mid;
                r = mid-1;
            }
        }
        return ans;
    }
};