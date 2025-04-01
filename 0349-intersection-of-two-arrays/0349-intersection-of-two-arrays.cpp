class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>us(nums1.begin(), nums1.end());
        set<int>ans;
        for(int i=0; i<nums2.size(); i++){
            if(us.count(nums2[i])) ans.insert(nums2[i]);
        }
        return vector<int>(ans.begin(), ans.end());
    }
};