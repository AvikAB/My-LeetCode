class Solution {
public:
    vector<vector<int>>res;
    void getSubsets(int pos, vector<int>&nums, vector<int>&current){
        if(pos==nums.size()){
            res.push_back(current);
            return;
        }
        current.push_back(nums[pos]);
        getSubsets(pos+1, nums, current);
        current.pop_back();
        getSubsets(pos+1, nums, current);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>current;
        getSubsets(0, nums, current);
        return res;
    }
};