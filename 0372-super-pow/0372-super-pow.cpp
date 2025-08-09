class Solution {
#define ll long long
public:
    ll m = 1337;  // here, 1337 isn't a prime num, thats why we need to find the phi of 1337
    // phi(1337) = (7-1)*(191-1) -> 1140
    ll p1 = 7, p2 = 191;
    ll phi_p1 = 6, phi_p2 = 190;

    ll bigmod(ll a, ll b, ll m){
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

    ll getNum(vector<int>& b, ll m){
        ll temp = 0;
        for(int d:b){
            temp = (temp*10+d) % m;
        }
        return temp;
    }

    int superPow(int a, vector<int>& b) {
        a %= m;
        
        // mod p1
        ll exp1 = getNum(b, phi_p1);
        if(exp1==0) exp1 += phi_p1;
        ll r1 = bigmod(a, exp1, p1);

        // mod p2
        ll exp2 = getNum(b, phi_p2);
        if(exp2==0) exp2 += phi_p2;
        ll r2 = bigmod(a, exp2, p2);

        // CRT - Chinese Remainder Theorem
        for(ll x=r1; ;x+=p1){
            if(x%p2==r2) return x;
        }
    }
};


/*
1337 = 7*191
The phi of 1337 = 1337 * (1-(1/7))*(1-(1/191))  // euler totient formula
                = 1337 * (6*190/1337)
                = 6*190
                = 1140

Now find the ans of a^(b%1140) % 1137.
Compute a^b modulo each prime factor separately:
    1. mod 7 → exponent reduced mod φ(7) = 6
    2. mod 191 → exponent reduced mod φ(191) = 190

After computing these, need CRT to combine the result.
    x≡r1 (mod 7), x≡r2 (mod 191)
you must find the unique x % 1337 that satisfies both congruences.
*/