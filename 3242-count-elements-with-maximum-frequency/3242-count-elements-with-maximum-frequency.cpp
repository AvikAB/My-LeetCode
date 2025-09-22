class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int>freq;
        for(int i=0; i<nums.size(); i++){
            freq[nums[i]]++;
        }
        int mxfr = 0;
        for(auto &p:freq){
            mxfr = max(mxfr, p.second);
        }
        int ans = 0;
        for(auto &p:freq){
            if(p.second == mxfr) ans += p.second;
        }
        return ans;
    }
};