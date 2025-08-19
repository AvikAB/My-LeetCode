class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>us(nums.begin(), nums.end());
        vector<int>ans;
        for(int i=1; i<=n; i++){
            if(!us.count(i)) ans.push_back(i);
        }
        return ans;
    }
};