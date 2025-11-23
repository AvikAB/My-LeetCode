class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, INT_MIN);
        dp[0] = 0;
        for(int x:nums){
            vector<int> temp = dp;
            for(int r=0; r<3; r++){
                int newR = (r + x % 3) % 3;
                temp[newR] = max(temp[newR], dp[r]+x);
            }
            dp = temp;
        }
        return dp[0];
    }
};

/*
dp[r] means max sum which leaves remainder r when divided by 3. For each number x in array:
Check what happens if we add this number to previous remainder groups
Update dp values accordingly
In the end, dp[0] will store the maximum sum divisible by 3.
*/