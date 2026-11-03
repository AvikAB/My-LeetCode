class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return (n*mx)-sum;
    }
};




/*
Let, doing all ele equal by its mx val. So sum of all eles are equal to max - curr eles sum.
=> (n*mx) - sum 
*/