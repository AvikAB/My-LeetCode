class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg = 0;
        for(auto av:nums){
            if(av==0) return 0;
            if(av<0) neg++;
        }
        if(neg%2==0) return 1;
        else return -1;
    }
};