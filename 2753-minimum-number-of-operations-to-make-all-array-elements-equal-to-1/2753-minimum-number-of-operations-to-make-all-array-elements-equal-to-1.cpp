class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = count(nums.begin(), nums.end(), 1);
        if(cnt1>0) return n-cnt1;
        int mnSteps = INT_MAX;
        for(int i=0; i<n; i++){
            int gcd = nums[i];
            for(int j=i+1; j<n; j++){
                gcd = __gcd(gcd, nums[j]);
                if(gcd==1){
                    mnSteps = min(mnSteps, j-i);
                    break;
                }
            }
        }
        if(mnSteps==INT_MAX) return -1;
        else return mnSteps+(n-1);
    }
};