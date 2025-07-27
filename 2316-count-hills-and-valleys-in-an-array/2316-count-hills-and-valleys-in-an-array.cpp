class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int cnt = 0;
        int i = 0, j = 1;
        while(j+1<nums.size()){
            if((nums[i]<nums[j] and nums[j]>nums[j+1]) or (nums[i]>nums[j] and nums [j]<nums[j+1])){
                cnt++;
                i = j;
            }
            j++;
        }
        return cnt;
    }
};