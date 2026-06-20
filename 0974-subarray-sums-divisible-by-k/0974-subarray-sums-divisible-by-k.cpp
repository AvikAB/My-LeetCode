class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int>freq;
        freq[0] = 1;
        int pref = 0, ans = 0;
        for(int i=0; i<n; i++){
            pref += nums[i];

            int rem = pref % k;
            if(rem<0) rem += k;  // make remainder non-neg

            ans += freq[rem];
            freq[rem]++;
        }
        return ans;
    }
};