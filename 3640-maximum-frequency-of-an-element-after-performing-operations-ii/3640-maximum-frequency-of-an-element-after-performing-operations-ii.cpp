class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int mxEle = *max_element(nums.begin(), nums.end()) + k;
        map<int, int>diff;
        unordered_map<int, int>freq;

        for(int i=0; i<nums.size(); i++){
            freq[nums[i]]++;
            int mnTargetRange = max(0, nums[i]-k);
            int mxTargetRange = min(mxEle, nums[i]+k);
            diff[mnTargetRange]++;
            diff[mxTargetRange+1]--;
            diff[nums[i]] += 0;
        }
    
        int res = 0;
        int cumSum = 0;
        for(auto it=diff.begin(); it!=diff.end(); it++){
            int target = it->first;
            it->second += cumSum;
            int targetFreq = freq[target];
            int need = it->second - targetFreq;

            int mxPossibleFreq = min(need, numOperations);
            res = max(res, targetFreq+mxPossibleFreq);
            cumSum = it->second;
        }
        return res;
    }
};