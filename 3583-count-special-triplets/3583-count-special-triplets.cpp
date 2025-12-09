class Solution {
public:
    // Two Pass Solution:
    int mod = 1e9+7;
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> left, right;
        for(int &av:nums){
            right[av]++;
        }
        int ans = 0;
        for(int &x:nums){
            right[x]--;    // this is the x, means I need 2*x from left and right side from this
            int l = left[2*x];
            int r = right[2*x];
            ans = (ans+(1LL*l*r)) % mod;
            left[x]++;    // curr num or x will be the left ele of the next num
        }
        return ans;
    }
};