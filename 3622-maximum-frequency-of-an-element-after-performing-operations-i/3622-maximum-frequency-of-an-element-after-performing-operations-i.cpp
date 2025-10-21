class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int mxEle = *max_element(nums.begin(), nums.end()) + k;
        vector<int> freq(mxEle+1, 0);
        for(auto &av:nums){
            freq[av]++;
        }
        for(int i=1; i<=mxEle; i++){   // prefix sum of freq
            freq[i] += freq[i-1];
        }
        int res = 0;
        for(int target=0; target<=mxEle; target++){
            if(freq[target]==0) continue;   // skip
            int mnTargetRange = max(0, target-k);
            int mxTargetRange = min(mxEle, target+k);
            int totCnt = freq[mxTargetRange] - (mnTargetRange>0 ? freq[mnTargetRange-1] : 0);
            int targetCnt = freq[target] - (target>0 ? freq[target-1] : 0);
            int need = totCnt - targetCnt;
            int mxPossibleFreq = targetCnt + min(need, numOperations);
            res = max(res, mxPossibleFreq);
        }
        return res;
    }
};