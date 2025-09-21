class Solution {
public:
    #define ll long long int
    const ll mod = 1e9+7;
    int countStableSubsequences(vector<int>& nums) {
        vector<ll> v(nums.begin(), nums.end());
        ll odd1 = 0, odd2 = 0;
        ll evn1 = 0, evn2 = 0;
        for(int av:v){
            if(av%2!=0){
                ll addOdd1 = (1+evn1+evn2) % mod;
                ll addOdd2 = odd1 % mod;
                odd1 = (odd1+addOdd1) % mod;
                odd2 = (odd2+addOdd2) % mod;
            } else {
                ll addEvn1 = (1+odd1+odd2) % mod;
                ll addEvn2 = evn1 % mod;
                evn1 = (evn1+addEvn1) % mod;
                evn2 = (evn2+addEvn2) % mod;
            }
        }
        return (odd1+odd2+evn1+evn2) % mod;
    }
};