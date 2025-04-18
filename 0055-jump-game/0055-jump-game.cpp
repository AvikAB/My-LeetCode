class Solution {
public:
    bool canJump(vector<int>& nums) {
        int minIdx = 0;
        for(int i=0; i<nums.size(); i++){
            if(i>minIdx) return false;
            minIdx = max(minIdx, i+nums[i]);
        }
        return true;
    }
};