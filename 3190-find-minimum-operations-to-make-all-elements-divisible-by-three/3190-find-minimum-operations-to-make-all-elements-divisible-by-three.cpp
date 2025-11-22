class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt = 0;
        for(auto av:nums){
            if(av%3!=0) cnt++;
        }
        return cnt;
    }
};