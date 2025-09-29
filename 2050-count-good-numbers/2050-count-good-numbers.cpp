class Solution {
public:
    #define ll long long
    const ll mod = 1e9+7;

    ll bigmod(ll a,ll b,ll m){
        if(b==0) return 1%m;
        if(b%2==0){
            ll t = bigmod(a,b/2,m);
            return (1LL*t*t%m);
        } else {
            ll t = bigmod(a,(b-1)/2,m);
            t = (1LL*t*t)%m;
            return (1LL*a*t%m);
        }
    }

    int countGoodNumbers(long long n) {
        ll evnPos = (n+1)/2;
        ll oddPos = n/2;
        ll evnWays = bigmod(5, evnPos, mod);
        ll oddWays = bigmod(4, oddPos, mod);
        return (int)((evnWays * oddWays)%mod);
    }
};


/* Odd indices has prime nums (2,3,5,7) -> total 4 choices. Even indices has even nums from 0 to 9 (0,2,4,6,8) -> total 5 choices. N is given, output the total nums of good digits.

N is the total pos, find the even pos -> n*(n+1)/2, remain positions are odd pos or we can use n/2. Then (4^odd) * (5^even) % mod;
*/