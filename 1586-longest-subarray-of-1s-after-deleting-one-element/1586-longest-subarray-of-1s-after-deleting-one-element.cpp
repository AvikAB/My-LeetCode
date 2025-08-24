class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0, j = 0;
        int LastZeroIdx = -1;
        int res = 0;
        while(j<nums.size()){
            if(nums[j]==0){
                i = LastZeroIdx+1;
                LastZeroIdx = j;
            }
            res = max(res, j-i);
            j++;
        }
        return res;
    }
};




/* Intuition: In the subarray we want only one '0' and that will be removed. So, the len of a subarray is, j-i+1. In that case, we want a optimal subarray where at least one '0' present there and then it will be removed. So the size will be (j-i+1)-1 = j-i. Simple sliding window approach - i & j starts from 0, j moves to right & track the last zero idx and when another '0' found then i = last zero idx + 1 beacuse we can't keep double zero in a subarray and find the mx Length of that subarray.
*/