class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int prefSum = 0;
        int mxLen = 0;
        unordered_map<int, int> prefMap;
        prefMap[0] = -1;
        for(int i=0; i<n; i++){
            prefSum += (nums[i]==1) ? 1:-1;  // it will check the diff

            if(prefMap.find(prefSum) != prefMap.end()){  // find the valid subarr, one diff=0 to another diff=0 will be valid subarr.
                int len = i - prefMap[prefSum];
                mxLen = max(mxLen, len);
            }
            else prefMap[prefSum] = i;
        }
        return mxLen;
    }
};