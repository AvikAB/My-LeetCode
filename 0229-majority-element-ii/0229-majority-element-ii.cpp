class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int,int>mp;
        vector<int>res;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        for(auto &av:mp){
            if(av.second>n/3){
                res.push_back(av.first);
            }
        }
        return res;
    }
};