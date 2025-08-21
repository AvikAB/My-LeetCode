class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            int gcd = nums[i];
            for(int j=i; j<nums.size(); j++){
                gcd = __gcd(gcd, nums[j]);
                if(gcd==k) cnt++;
                if(gcd<k) break;  // if gcd <k then any next greater ele & that gcd's gcd will be always less than k, break works for i
            }
        }
        return cnt;
    }
};