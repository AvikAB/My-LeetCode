class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int>ans;
        for(auto av:nums){
            ans.push_back(nums[av]);
        }
        return ans;
    }
};