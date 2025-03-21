class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>cnt;
        long long sum = 0, ans = 0;
        cnt[0] = 1;
        for(auto av:nums){
            sum += av;
            ans += cnt[sum-k];
            cnt[sum]++;
        }
        return ans;
    }
};