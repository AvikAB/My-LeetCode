class Solution {
public:
    #define ll long long
    const ll MOD = 1e9+7;
    int numOfWays(int n) {
        vector<ll> a(n,6), b(n,6);
        for(int i=1; i<n; i++){
            a[i] = (2*a[i-1] + 2*b[i-1]) % MOD;
            b[i] = (2*a[i-1] + 3*b[i-1]) % MOD;
        }
        return (a[n-1] + b[n-1]) % MOD;
    }
};

/*
There are total 2 patterns, 
    1. a[i] = ways where col i uses 3 diff colors.
    2. b[i] = ways where col i uses top and bottom cell same color.

For the first col: Both patterns have 6 possible ways.
For each new col: 
    1. A col with diff colors can come from both previous patterns in 2 ways each.
    2. A col with same top and bottom came from:
        1. diff color pattern in 2 ways.
        2. same color pattern in 3 ways.
Final answer: a[n-1] + b[n-1]
*/