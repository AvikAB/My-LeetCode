class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int i = 0;
        /* Intuition: for sorting, 0 will be placed in left side and 2 will be placed  in right side. Just code will work for that then automatically 1 will be placed in the middle. */
        while(i<=right){
            if(nums[i]==0){
                swap(nums[i], nums[left]);
                left++, i++;
            } else if(nums[i]==2){
                swap(nums[i], nums[right]);
                right--;    // after swapping i++ will be not working here because it will check that the current element after swapping is 0, 1 or 2. 
            } else {  // if the element is 1 then it will be placed here (middle place)
                i++;
            }
        }
    }
};