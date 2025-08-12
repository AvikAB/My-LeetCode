class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        n = n/2;
        for(auto av:mp){
            if(av.second>n) return av.first;
        }
        return 0;
    }
};