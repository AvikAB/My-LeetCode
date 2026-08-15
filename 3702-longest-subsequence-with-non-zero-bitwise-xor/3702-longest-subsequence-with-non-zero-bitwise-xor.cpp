class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xorr = 0;
        bool allzero = true;
        for(auto av:nums){
            xorr ^= av;
            if(av!=0) allzero = false;
        }
        if(allzero) return 0;
        else if(xorr==0) return n-1;
        else return n;
    }
};