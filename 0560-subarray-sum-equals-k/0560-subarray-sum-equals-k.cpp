class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int>freq;
        freq[0] = 1;
        int prefix = 0, ans = 0;
        for(int i=0; i<nums.size(); i++){
            prefix += nums[i];
            ans += freq[prefix-k];
            freq[prefix]++;
        }
        return ans;
    }
};