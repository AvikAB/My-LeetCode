class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = LLONG_MIN, sec = LLONG_MIN, third = LLONG_MIN;
        for(auto av:nums){
            if(av==first or av==sec or av==third) continue;
            if(av>first){
                third = sec;
                sec = first;
                first = av;
            } else if(av>sec){
                third = sec;
                sec = av;
            } else if(av>third) third = av;
        }
        return (third==LLONG_MIN) ? first:third;  // if third is still LLONG_MIN then it can't find the third max then return the max num
    }
};