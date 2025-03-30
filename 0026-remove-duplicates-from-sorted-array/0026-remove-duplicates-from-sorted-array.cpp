class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,bool>seen;
        for(int i=0; i<nums.size(); i++){
            if(seen.count(nums[i])>0) continue;
            seen[nums[i]] = true;
            ans.push_back(nums[i]);
        }
        nums = ans;   // here its says that should update 'nums' not print secondary dataset directly
        return ans.size();
    }
};