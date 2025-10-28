class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int leftSum = 0, rightSum = 0;
        for(auto av:nums){
            rightSum += av;
        }
        for(int i=0; i<n; i++){
            leftSum += nums[i];
            rightSum -= nums[i];
            if(nums[i]!=0) continue;  // must start from '0'
            if(leftSum==rightSum) cnt += 2;
            if(abs(leftSum-rightSum)==1) cnt++;
        }
        return cnt;
    }
};


/*
When starting at a zero, the sum of values on the left and sum of values on the right determine validity. If leftSum == rightSum, both directions work (+2). If they differ by 1, one direction works (+1)
*/