class Solution {
public:
    #define ll long long
    const ll mod = 1e9+7;
    int zigZagArrays(int n, int l, int r) {
        int m = r-l+1;
        if(n==1) return m % mod;
        vector<ll> up(m), dwn(m);
        for(int i=0; i<m; i++){
            up[i] = i;
            dwn[i] = m-1-i;
        }
        vector<ll>pref(m), suff(m);
        vector<ll> nUp(m), nDwn(m);
        for(int i=3; i<=n; i++){
            ll sum = 0;
            for(int j=0; j<m; j++){
                sum = (sum+dwn[j])%mod;
                pref[j] = sum;
            }
            sum = 0;
            for(int j=m-1; j>=0; j--){
                sum = (sum+up[j])%mod;
                suff[j] = sum;
            }
            for(int z=0; z<m; z++){
                if(z>0) nUp[z] = pref[z-1];
                else nUp[z] = 0;
                if(z+1<m) nDwn[z] = suff[z+1];
                else nDwn[z] = 0;
            }
            up = nUp;
            dwn = nDwn;
        }
        ll ans = 0;
        for(int i=0; i<m; i++){
            ans = (ans+up[i]+dwn[i])%mod;
        }
        return ans;
    }
};