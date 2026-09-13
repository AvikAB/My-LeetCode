class Solution {
public:
    #define ll long long
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int m = n/2;
        ll tot = 0;
        for(auto av:nums){
            tot += av;
        }
        ll wsum = 0;
        for(int i=0; i<m; i++){
            wsum += nums[i];
        }
        ll ans = 0;
        for(int i=0; i<n; i++){
            if(2*wsum>tot) ans++;
            wsum -= nums[i];
            wsum += nums[(i+m)%n];
        }
        return ans;
    }
};