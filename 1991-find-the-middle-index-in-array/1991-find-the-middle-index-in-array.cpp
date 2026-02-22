class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        // prefix sum
        vector<int> pref(n+1, 0);
        for(int i=0; i<n; i++){
            pref[i+1] = pref[i] + nums[i];
        }
        int totSum = pref[n];
        // suffix sum
        vector<int> suff(n+1, 0);
        for(int i=0; i<n; i++){
            suff[i] = totSum - pref[i];
        }

        for(int i=0; i<n; i++){
            if(pref[i]==suff[i+1]) return i;
        }
        return -1;
    }
};