class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        map<int, int>m;
        for(int av:nums){
            m[av]++;
        }
        while(original<=1000 and m[original]!=0){
            original *= 2;
        }
        return original;
    }
};