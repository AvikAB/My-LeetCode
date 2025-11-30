class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long sum = 0;
        for(auto av:nums){
            sum += av;
        }
        long long target = sum % p;
        if(target==0) return 0;  // no need to remove any ele, its already divisible by p

        unordered_map<int, int> mp;   // it will store (prefix_sum % p) and their idx
        int curr = 0;   // prefix_sum
        mp[0] = -1;
        int res = n;  // n beacuse its said the min length of subarray

        for(int i=0; i<n; i++){
            curr = (curr+nums[i]) % p;
            int need = (curr - target + p) % p;   // +p for avoiding negative val of modulus
            if(mp.count(need)) res = min(res, i-mp[need]);  // mp[need] will gives us 'j' pointer
            mp[curr] = i;   // store the prefix_sum into the map
        }
        return res==n ? -1 : res;
    }
};