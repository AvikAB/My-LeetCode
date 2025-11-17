class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prevPos = -1e9;   // -1e9 for handle edge case of the first occurence of 1
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1){
                if(i-prevPos<=k) return false;
                else prevPos = i;
            }
        }
        return true;
    }
};