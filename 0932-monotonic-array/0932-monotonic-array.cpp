class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = false, dec = false;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]>nums[i-1]) inc = true;
            else if(nums[i]<nums[i-1]) dec = true;
        }
        if(inc and dec) return false;
        else return true;
    }
};