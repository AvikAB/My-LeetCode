class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int unique = 1;
        int j = i+1;
        while(j<n){
            if(nums[j]==nums[j-1]){  // equal
                j++;
            } else {  // else its unique
                nums[i+1] = nums[j];
                unique++;
                i++;
                j++;
            }
        }
        return unique;
    }
};