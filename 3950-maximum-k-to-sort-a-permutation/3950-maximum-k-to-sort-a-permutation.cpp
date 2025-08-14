class Solution {
public:
    bool isPos(vector<int>nums, int k){
        vector<int>idx;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if((nums[i] & k)==k) idx.push_back(i);
        }
        vector<int>v;
        for(auto av:idx) v.push_back(nums[av]);
        sort(v.begin(), v.end());
        for(int i=0; i<idx.size(); i++){
            nums[idx[i]] = v[i];
        }
        return is_sorted(nums.begin(), nums.end());
    }
    int sortPermutation(vector<int>& nums) {
        if(is_sorted(nums.begin(), nums.end())) return 0;
        int ans = 0;
        for(int i=30; i>=0; i--){
            int x = ans | (1<<i);
            if(isPos(nums, x)) ans = x;
        }
        return ans;
    }
};