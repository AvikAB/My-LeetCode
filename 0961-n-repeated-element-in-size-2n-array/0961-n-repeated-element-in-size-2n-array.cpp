class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size()/2;
        map<int, int>m;
        for(auto av:nums){
            m[av]++;
        }
        int ans = 0;
        for(auto av:m){
            int val = av.first;
            int freq = av.second;
            if(freq==n){
                ans = val;
                break;
            }
        }
        return ans;
    }
};