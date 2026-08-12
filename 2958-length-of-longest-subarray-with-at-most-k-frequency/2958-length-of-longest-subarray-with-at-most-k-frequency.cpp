class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int ans = 0;
        map<int,int>freq;
        for(int r=0; r<n; r++){
            freq[nums[r]]++;
            while(freq[nums[r]]>k){
                freq[nums[l]]--;
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};