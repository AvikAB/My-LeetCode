class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = INT_MAX;
        int mx = INT_MIN;
        unordered_set<int>seen;
        for(int x:nums){
            mn = min(mn, x);
            mx = max(mx, x);
            seen.insert(x);
        }
        vector<int>ans;
        for(int i=mn+1; i<mx; i++){
            if(!seen.count(i)) ans.push_back(i);
        }
        return ans;
    }
};