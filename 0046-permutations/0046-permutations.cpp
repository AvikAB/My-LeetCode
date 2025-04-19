class Solution {
public:
    vector<vector<int>>res;
    void getPermute(int pos, vector<int>&nums){
        if(pos==nums.size()-1){
            res.push_back(nums);
            return;
        }
        for(int i=pos; i<nums.size(); i++){
            swap(nums[pos], nums[i]);
            getPermute(pos+1, nums);
            swap(nums[pos], nums[i]);  // backtrack
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        getPermute(0, nums);
        return res;
    }
};