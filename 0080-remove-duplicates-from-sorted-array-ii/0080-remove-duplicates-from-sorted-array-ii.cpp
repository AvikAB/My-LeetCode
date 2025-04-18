class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2) return nums.size();
        int start = 1;
        for(int i=2; i<nums.size(); i++){
            if(nums[i]!=nums[start-1]){
                start++;
                nums[start] = nums[i];
            }
        }
        return start+1;
    }
};