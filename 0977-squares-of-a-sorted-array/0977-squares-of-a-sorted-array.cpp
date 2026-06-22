class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            nums[i] = nums[i]*nums[i];
        }
        int i=0, j=n-1;
        int pos = n-1;
        vector<int>ans(n);
        while(i<=j){
            if(nums[i]>nums[j]){
                ans[pos] = nums[i];
                i++;
            } else {
                ans[pos] = nums[j];
                j--;
            }
            pos--;
        }
        return ans;
    }
};