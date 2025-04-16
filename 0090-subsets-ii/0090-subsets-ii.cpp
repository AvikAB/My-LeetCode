class Solution {
public:
    vector<vector<int>>res;
    void getsubsets(int pos, vector<int>&nums, vector<int>&current){
        res.push_back(current);
        for(int i=pos; i<nums.size(); i++){
            if(i>pos and nums[i]==nums[i-1]) continue;  // skip the same ele
            current.push_back(nums[i]);
            getsubsets(i+1, nums, current);
            current.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>current;
        getsubsets(0, nums, current);
        return res;
    }
};