class Solution {
public:
    bool isPos(const vector<int>&nums){
        for(int i=1; i<nums.size(); i++){
            if(nums[i]<nums[i-1]){
                return false;
            }
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;
        while(!isPos(nums)){
            int mnSum = INT_MAX;
            int idx = -1;
            for(int i=0; i<nums.size()-1; i++){
                int sum = nums[i]+nums[i+1];
                if(sum<mnSum){
                    mnSum = sum;
                    idx = i;
                }
            }
            nums[idx] = mnSum;
            nums.erase(nums.begin()+idx+1);
            ops++;
        }
        return ops;
    }
};