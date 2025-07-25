class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = n;
        for(int i=0; i<n; i++){
            if(nums[i]>=target){
                return i;
                break;
            }
        }
        return n;
    }
};