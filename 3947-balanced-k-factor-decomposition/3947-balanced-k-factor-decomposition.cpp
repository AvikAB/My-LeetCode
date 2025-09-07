class Solution {
    #define ll long long
private:
    vector<ll>ans;
    ll best;
    void decomp(ll n, ll k, vector<ll>&path, ll mn){
        if(k==1){
            path.emplace_back(n);
            ll sm = *min_element(path.begin(), path.end());
            ll lar = *max_element(path.begin(), path.end());
            ll gap = lar-sm;
            if(gap<best){
                best = gap;
                ans = path;
            }
            path.pop_back();
            return;
        }
        if(mn==1){
            path.push_back(1);
            decomp(n, k-1, path, 1);
            path.pop_back();
        }

        for(int p=mn; p*p<=n; p++){
            if(n%p==0){
                path.push_back(p);
                decomp(n/p, k-1, path, p);
                path.pop_back();
            }
        }
    }
    
public:
    vector<int> minDifference(int n, int k) {
        best = LLONG_MAX;
        ans.clear();
        vector<ll>path;
        decomp(n, k, path, 1);
        vector<int>a;
        a.reserve(ans.size());
        for(ll x:ans) a.push_back((int)x);
        return a;
    }
};