class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            int lcm = nums[i];
            for(int j=i; j<nums.size(); j++){
                lcm = (lcm / __gcd(lcm, nums[j])) * nums[j];
                if(lcm==k) cnt++;
                if(lcm>k) break;  // lcm is non-decreasing as i extend the subarr, if it exceeds k, it can never be go back down to k.
            }
        }
        return cnt;
    }
};