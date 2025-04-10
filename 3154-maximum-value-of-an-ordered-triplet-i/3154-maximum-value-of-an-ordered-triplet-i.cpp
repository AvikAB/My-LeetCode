class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long int n = nums.size();
        long long int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    long long int val = ((nums[i]-nums[j])*1LL*nums[k]);
                    ans = max(ans, val);
                }
            }
        }
        return ans;
    }
};