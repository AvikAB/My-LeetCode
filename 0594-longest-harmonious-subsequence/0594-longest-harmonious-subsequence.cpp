class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0, j = 0;
        int len = 0;
        while(j<n){
            while(nums[j]-nums[i]>1 and i<=j){
                i++;
            }
            if(nums[j]-nums[i]==1){
                len = max(len, j-i+1);
            }
            j++;
        }
        return len;
    }
};