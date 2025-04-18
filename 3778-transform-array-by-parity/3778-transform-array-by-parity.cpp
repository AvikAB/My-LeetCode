class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        vector<int>v;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2) v.push_back(1);
            else v.push_back(0);
        }
        sort(v.begin(), v.end());
        return v;
    }
};