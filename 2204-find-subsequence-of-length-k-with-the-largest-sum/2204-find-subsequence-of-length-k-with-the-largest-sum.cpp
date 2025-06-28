class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>>vp;   // [val, idx] pair
        for(int i=0; i<nums.size(); i++){
            vp.push_back({nums[i], i});
        }
        sort(vp.rbegin(), vp.rend());  // sort in descending order
        vector<pair<int,int>> topKele(vp.begin(), vp.begin()+k);   // take topK elements
        //sort the original idx in ascending order
        sort(topKele.begin(), topKele.end(), [](auto &a, auto &b){  
            return a.second < b.second;
        });
        vector<int> ans;
        for(auto av:topKele){
            ans.push_back(av.first);
        }
        return ans;
    }
};