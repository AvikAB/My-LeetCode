class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sin = 0, dou = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>9) dou += nums[i];
            else sin += nums[i];
        }
        if(sin != dou) return true;
        else return false;
    }
};