class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1 or nums.empty()) return 0;   // edge case
        int n = nums.size();
        int cnt = 0;
        int prod = 1;
        int l = 0, r = 0;
        while(r<n){
            prod *= nums[r];
            while(prod>=k and l<=r){   // shrink the window from the left side
                prod /= nums[l];
                l++;   // move the left pointer to the right side
            }
            cnt += (r-l+1);   // num of subarray ending at r
            r++;    // move the right pointer
        }
        return cnt;
    }
};