class Solution {
public:
    #define ll long long
    long long maxTotalValue(vector<int>& nums, int k) {
        ll mx = *max_element(nums.begin(), nums.end());
        ll mn = *min_element(nums.begin(), nums.end());
        ll diff = mx - mn;
        return diff*k;
    }
};