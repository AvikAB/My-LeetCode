class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=0){
                swap(nums[i], nums[pos]);
                pos++;
            }
        }
    }
};

// non-zero eles are swap with the pos, do nothing to pos when ele is 0, else increment.