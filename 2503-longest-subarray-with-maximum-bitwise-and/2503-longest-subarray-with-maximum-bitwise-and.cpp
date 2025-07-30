class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        if(nums.empty()) return 0;

        // find the max val in the array, mxVal will be the maximum possible bitwise AND
        int mxVal = 0;
        for(auto av:nums){
            if(av>mxVal) mxVal = av;
        }

        // Find the length of longest subarray of mxVal
        int mxLen = 0;
        int currLen = 0;
        for(auto av:nums){
            if(av==mxVal) currLen++;
            else {
                mxLen = max(mxLen, currLen);
                currLen = 0;
            }
        }

        // final check for a trailing streak
        return max(mxLen, currLen);
    }
};