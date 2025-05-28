class Solution {
public:
    int digitSum(int n){
        int s = 0;
        while(n){
            int ld = n%10;
            s += ld;
            n /= 10;
        }
        return s;
    }

    int differenceOfSum(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int digSum = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>9) digSum += digitSum(nums[i]);
            else digSum += nums[i];
        }
        return abs(sum-digSum);
    }
};