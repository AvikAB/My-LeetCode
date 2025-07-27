class Solution {
public:
    #define ll long long int
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        ll sum = 0, n = nums.size(), k = n/3;
        ll i = n-2;
        while(k){
            sum += nums[i];
            i -= 2;
            k--;
        }
        return sum;
    }
};