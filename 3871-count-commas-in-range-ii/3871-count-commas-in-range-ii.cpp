class Solution {
public:
    #define ll long long
    long long countCommas(long long n) {
        ll cnt = 0;
        ll start = 1000;
        while(start<=n){
            cnt += (n-start+1);
            start *= 1000;
        }
        return cnt;
    }
};



/*
Range 10^6 -1 = 1 comma, 10^9 -1 = 2 commas, 10^12 -1 = 3 commas, 10^15 -1 = 4 commas
*/