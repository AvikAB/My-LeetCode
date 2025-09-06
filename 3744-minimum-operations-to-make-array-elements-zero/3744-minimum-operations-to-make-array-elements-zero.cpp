class Solution {
public:
    #define ll long long
    ll solve(ll l, ll r){
        ll L = 1;
        ll S = 1;
        ll steps = 0;
        while(L<=r){
            ll R = 4*L-1;
            ll start = max(L, l);
            ll end = min(R, r);
            if(start<=end){
                steps += (end-start+1)*S;
            }
            S++;
            L *= 4;
        }
        return steps;
    }
    long long minOperations(vector<vector<int>>& queries) {
        ll res = 0;
        for(auto &q:queries){
            ll l = q[0];
            ll r = q[1];
            ll steps = solve(l, r);
            res += (steps+1)/2;
        }
        return res;
    }
};