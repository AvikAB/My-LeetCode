class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>cnt;
        for(auto av: nums){
            if(cnt[av]>0) return av;
            cnt[av]++;
        }
        return -1;
    }
};