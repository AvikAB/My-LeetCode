class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int curr = 0;
        for(auto bit:nums){
            curr = (curr*2+bit)%5;
            ans.push_back(curr==0);
        }
        return ans;
    }
};


/*
Multipy by 2 (left shift) for create a extra space in right side for every bit. + bit = place the new bit in that rightmost position. 
*/