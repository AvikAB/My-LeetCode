class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int>m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        for(auto av:m){
            if(av.second>2) return false;
        }
        return true;
    }
};