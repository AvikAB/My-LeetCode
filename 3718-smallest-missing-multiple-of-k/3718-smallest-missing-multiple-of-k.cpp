class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>hash(nums.begin(), nums.end());
        int curr = k;
        while(hash.count(curr)){
            curr += k;
        }
        return curr;
    }
};