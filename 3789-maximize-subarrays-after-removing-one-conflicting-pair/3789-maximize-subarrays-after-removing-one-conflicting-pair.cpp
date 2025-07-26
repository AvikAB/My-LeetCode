class Solution {
public:
    #define ll long long
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        ll valid = 0;
        vector<vector<ll>> conflictPoints(n+1);
        for(auto &p:conflictingPairs){
            // [a,b]
            ll a = min(p[0], p[1]);
            ll b = max(p[0], p[1]);
            conflictPoints[b].push_back(a);   // [1,2,3,a,...,b,..]
        }

        ll maxConf = 0, secMaxConf = 0;
        vector<ll>extra(n+1);
        // extra[i] = num of extra subarrays by removing the conflicting point i
        for(int end=1; end<=n; end++){
            for(auto &av:conflictPoints[end]){   //check all conflicting points of end
                if(av >= maxConf){
                    secMaxConf = maxConf;
                    maxConf = av;
                } else if(av > secMaxConf){
                    secMaxConf = av;
                }
            }
            valid += end - maxConf;
            extra[maxConf] += maxConf - secMaxConf;
        }
        return valid + *max_element(extra.begin(), extra.end());
    }
};