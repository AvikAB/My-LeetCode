class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>freq;
        for(int i=0; i<=n-k; i++){
            unordered_set<int>unique;
            for(int j=i; j<i+k; j++){
                unique.insert(nums[j]);
            }

            for(int av:unique){
                freq[av]++;
            }
        }

        int mxMiss = -1;
        for(auto &av:freq){
            if(av.second==1) mxMiss = max(mxMiss, av.first);
        }
        return mxMiss;
    }
};