class Solution {
public:
    #define ll long long
    long long subArrayRanges(vector<int>& nums) {
        ll sum = 0;
        ll n = nums.size();
        for(int i=0; i<n; i++){
            ll mn = nums[i];
            ll mx = nums[i];
            for(int j=i; j<n; j++){
                mn = min(mn, (ll)nums[j]);
                mx = max(mx, (ll)nums[j]);
                sum += (mx-mn);
            }
        }
        return sum;
    }
};