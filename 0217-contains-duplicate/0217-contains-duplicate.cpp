class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int>cnt;
        for(auto av: nums){
            if(cnt[av]>0){
                return true;
            }
            cnt[av]++;
        }
        return false;
    }
};